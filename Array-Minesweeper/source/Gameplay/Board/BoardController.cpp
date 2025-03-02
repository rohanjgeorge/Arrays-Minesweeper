#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"



namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;
		using namespace Global;
		using namespace Sound;

		BoardController::BoardController()
		{
			board_view = new BoardView(this);
			createBoard();
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::createBoard()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					board[a][b] = new CellController(sf::Vector2i(a, b));
				}
			}
		}

		void BoardController::initializeCells()
		{
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();

			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					board[a][b]->initialize(cell_width, cell_height);
				}
			}
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			initializeCells();
			reset();
		}

		void BoardController::update()
		{
			board_view->update();

			for (int row = 0; row < number_of_rows; ++row)
			{
				for (int col = 0; col < number_of_columns; ++col)
				{
					board[row][col]->update();
				}
			}
		}

		void BoardController::render()
		{
			board_view->render();

			for (int row = 0; row < number_of_rows; ++row)
			{
				for (int col = 0; col < number_of_columns; ++col)
				{
					board[row][col]->render();
				}
			}
		}

		void BoardController::reset()
		{
			resetBoard();

			board_state = BoardState::FIRST_CELL;
			//flagged_cells = 0;
		}

		BoardState BoardController::getBoardState()
		{
			return board_state;
		}

		void BoardController::setBoardState(BoardState state)
		{
			board_state = state;
		}

		void BoardController::deleteBoard()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_columns; b++)
				{
					delete board[a][b];
				}
			}
		}

		void BoardController::destroy()
		{
			deleteBoard();
			delete (board_view);
		}

		void BoardController::resetBoard()
		{
			for (int row = 0; row < number_of_rows; ++row)
			{
				for (int col = 0; col < number_of_columns; ++col)
				{
					board[row][col]->reset();
				}
			}
		}
	}
}
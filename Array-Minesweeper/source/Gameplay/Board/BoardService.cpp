#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include <iostream>

namespace Gameplay
{
	namespace Board
	{

		using namespace Cell;
		using namespace UI;
		using namespace UI::UIElement;

		BoardService::BoardService()
		{
			board_controller = nullptr;
		}

		BoardService::~BoardService()
		{
			destroy();
		}

		void BoardService::initialize()
		{
			if (board_controller != nullptr) {
				std::cerr << "ERROR: `board_controller` was already allocated! Deleting old instance..." << std::endl;
				delete board_controller;
			}

			board_controller = new BoardController();

			if (board_controller == nullptr) {
				std::cerr << "ERROR: Failed to allocate `BoardController`!" << std::endl;
				return;
			}

			std::cout << " BoardController successfully created!" << std::endl;
			board_controller->initialize();
		}

		void BoardService::update()
		{
			board_controller->update();
		}

		void BoardService::render()
		{
			board_controller->render();
		}

		void BoardService::processCellInput(CellController* cell_controller, ButtonType button_type)
		{
			board_controller->processCellInput(cell_controller, button_type);
		}

		BoardState BoardService::getBoardState()
		{
			return board_controller->getBoardState();
		}

		void BoardService::setBoardState(BoardState state)
		{
			board_controller->setBoardState(state);
		}

		void BoardService::resetBoard()
		{
			board_controller->reset();
		}

		int BoardService::getMinesCount()
		{
			return board_controller->getMinesCount();
		}

		void BoardService::flagAllMines() { board_controller->flagAllMines(); }

		void BoardService::showBoard() { board_controller->showBoard(); }

		void BoardService::destroy()
		{
			delete(board_controller);
		}
	}
}
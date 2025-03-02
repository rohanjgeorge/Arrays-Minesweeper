#pragma once
#include <sfml/Graphics.hpp>
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Board/BoardView.h"

namespace Gameplay {

	namespace Board
	{

		class BoardView;

		enum class BoardState
		{
			FIRST_CELL,     // The state when the player opens first cell.
			PLAYING,        // The game is in progress.
			COMPLETED,      // The game is over.
		};

		class BoardController
		{
		public:

			static const int number_of_rows = 9;
			static const int number_of_columns = 9;
			static const int mines_count = 8;

			BoardController();
			~BoardController();

			void initialize();
			void update();
			void render();
			void reset();

			BoardState getBoardState();
			void setBoardState(BoardState state);

		private:
			BoardView* board_view;
			Cell::CellController* board[number_of_rows][number_of_columns];



			BoardState board_state;

			void createBoard();
			void initializeCells();
			void destroy();
			void resetBoard();
			void deleteBoard();
		};
	}
}
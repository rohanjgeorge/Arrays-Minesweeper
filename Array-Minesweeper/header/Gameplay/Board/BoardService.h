#pragma once
#include "../../header/Gameplay/Board/BoardController.h"

namespace Gameplay
{
    namespace Board
    {
        class BoardService
        {
        private:
            Board::BoardController* board_controller;

            void destroy();

        public:
            BoardService();
            ~BoardService();
            void initialize();
            void update();
            void render();

            BoardState getBoardState();
            void setBoardState(BoardState state);
            void resetBoard();
        };
    }
}
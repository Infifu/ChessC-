#include "Board.h"
#include "Piece.h"
#include "Pawn.h"

Board::Board() 
{
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			grid[i][j] = nullptr;
		}
	}
}

void Board::display()
{
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (grid[i][j] != nullptr) {
				std::cout << grid[i][j]->getPieceSymbol() << " ";
			}
			else {
				std::cout << "# ";
			}
		}
		std::cout << std::endl;
	}
}

void Board::intialise()
{
	for (int j = 0; j < 8; j++)
	{
		grid[6][j] = new Pawn(true);
		grid[1][j] = new Pawn(false);
	}

}

bool Board::movePiece(int fromX, int fromY, int toX, int toY)
{
	return false;
}
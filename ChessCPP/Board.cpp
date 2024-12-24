#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "stdafx.h"
#include <iostream>
#include <string>

Board::Board() 
{
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			_grid[i][j] = nullptr;
		}
	}
}

void Board::display()
{
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (_grid[i][j] != nullptr) {
				std::cout << _grid[i][j]->getPieceSymbol() << " ";
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
	//black = false, white = true
	for (int j = 0; j < 8; j++)
	{
		_grid[6][j] = new Pawn(true); //white white pawns
		_grid[1][j] = new Pawn(false); //black pawns
	}

	//Rooks
	_grid[7][0] = new Rook(true);
	_grid[7][7] = new Rook(true);
	_grid[0][0] = new Rook(false);
	_grid[0][7] = new Rook(false);

}

bool Board::movePiece(int fromX, int fromY, int toX, int toY)
{
	return false;
}

// [][]
// row col                                      e2
std::string Board::indexToNumber(std::string location)
{
	std::string result;
	int chessNumbers[8] = {7,6,5,4,3,2,1,0};
	char letter = location[0];
	int letterInt = letter - 'a';
	int number = location[1] - '0' - 1;
	number = chessNumbers[number];
	result = std::to_string(number); //row
	result += std::to_string(letterInt); //col
	return result;
}

int Board::checkMove(std::string msgFromGraphics)
{
	std::string from;
	std::string to;
	std::string result;
	std::string resultTo;
	Piece* fromPiece;
	Piece* toPiece;
	int FromRow;
	int ToRow;
	int FromCol;
	int ToCol;

	from += msgFromGraphics[0];
	from += msgFromGraphics[1];
	to += msgFromGraphics[2];
	to += msgFromGraphics[3];

	result = indexToNumber(from);
	resultTo = indexToNumber(to);
	FromRow = int(result[0]) - 48;
	ToRow = int(resultTo[0]) - 48;
	FromCol = int(result[1]) - 48;
	ToCol = int(resultTo[1]) - 48;

	fromPiece = _grid[FromRow][FromCol];
	toPiece = _grid[ToRow][ToCol];
	if (toPiece == nullptr && fromPiece->validmoves(result, resultTo))
	{
		_grid[FromRow][FromCol] = nullptr;
		_grid[ToRow][ToCol] = fromPiece;
		delete(toPiece);
		return 0;
	}

	if (fromPiece == nullptr)
	{
		return 2; //there is not current piece
	}
	if (toPiece != nullptr && fromPiece != nullptr)
	{
		return 3; //same player figures
	}
	if (fromPiece->validmoves(result, resultTo))
	{
		_grid[FromRow][FromCol] = nullptr;
		_grid[ToRow][ToCol] = fromPiece;
		delete(toPiece);
	}

	return 6;
}

#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(bool color) : Piece(color), _promoted(false),_promotedTo(nullptr),_moveDirection(true)
//black = false, white = true
//moveDirection, true = normal , false = reversed
{
	if (color)
	{
		_pieceSymbol = "P";
	}
	else
	{
		_pieceSymbol = "p";
	}
}

bool Pawn::validmoves(std::string currPositon, std::string goalPosition)
{
	return false;
}

void Pawn::attackSquares(std::string currPositon, std::string goalPosition)
{
}

void Pawn::captureFreeMoves()
{
}

bool Pawn::toBECaptured()
{
	return false;
}

#include "Pawn.h"

Pawn::Pawn(bool color) : Piece(color), promoted(false),promotedTo(nullptr),moveDirection(true)
//black = false, white = true
//moveDirection, true = normal , false = reversed
{
	if (color)
	{
		pieceSymbol = "P";
	}
	else
	{
		pieceSymbol = "p";
	}
}

void Pawn::validmoves()
{
}

void Pawn::attackSquares()
{
}

void Pawn::captureFreeMoves()
{
}

bool Pawn::toBECaptured()
{
	return false;
}

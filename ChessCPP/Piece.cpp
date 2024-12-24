#include "Piece.h"

Piece::Piece(bool color) : PieceColor(color),pieceSymbol("") {}

std::string Piece::getPieceSymbol() const
{
	return pieceSymbol;
}


void Piece::validmoves()
{
}

void Piece::attackSquares()
{
}

void Piece::captureFreeMoves()
{
}

bool Piece::toBECaptured()
{
	return false;
}

#include "Piece.h"

Piece::Piece(bool color) : _pieceColor(color),_pieceSymbol(""),_placeAt("") {}

std::string Piece::getPieceSymbol() const
{
	return _pieceSymbol;
}

bool validmoves(std::string currPositon, std::string goalPosition)
{
	return false;
}

void Piece::captureFreeMoves()
{
}

bool Piece::toBECaptured()
{
	return false;
}

bool Piece::getPieceColor()
{
	return _pieceColor;
}

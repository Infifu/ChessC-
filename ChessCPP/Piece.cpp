#include "Piece.h"

Piece::Piece(Color color) : _pieceColor(color),_pieceSymbol(""),_placeAt("") {}

std::string Piece::getPieceSymbol() const
{
	return _pieceSymbol;
}

bool validmoves(std::string currPositon, std::string goalPosition, Piece* (&grid)[8][8])
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

int Piece::getPieceColor() const
{
	return _pieceColor;
}

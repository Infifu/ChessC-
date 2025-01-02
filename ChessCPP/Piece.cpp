#include "Piece.h"

Piece::Piece(Color color) : _pieceColor(color),_pieceSymbol(""),_placeAt("") {}

/**
 * @brief get the pieces symbol
 * @return return the piece symbol
 */
std::string Piece::getPieceSymbol() const
{
	return _pieceSymbol;
}

bool validmoves(std::string currPositon, std::string goalPosition, Piece* (&grid)[8][8])
{
	return false;
}

/**
 * @brief get the piece color
 * @return the piece color bro
 */
int Piece::getPieceColor() const
{
	return _pieceColor;
}

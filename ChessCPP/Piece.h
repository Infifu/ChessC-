#pragma once
#include <iostream>

class Piece
{
protected:
	bool PieceColor;
	std::string PlaceAt;
	std::string pieceSymbol;
public:
	Piece(bool color); //black = false, white = true
	std::string getPieceSymbol() const;
	virtual void validmoves() = 0;
	virtual void attackSquares() = 0;
	virtual void captureFreeMoves() = 0;
	virtual bool toBECaptured() = 0;
};


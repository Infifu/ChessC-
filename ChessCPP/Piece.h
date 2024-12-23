#pragma once
#include <iostream>

class Piece
{
private:
	std::string PieceColor;
	std::string PlaceAt;
	bool moved;
public:
	virtual void validmoves() = 0;
	virtual void attackSquares() = 0;
	virtual void captureFreeMoves() = 0;
	virtual bool toBECaptured() = 0;
};


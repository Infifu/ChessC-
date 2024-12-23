#pragma once
#include <iostream>

class Piece
{
private:
	std::string PieceColor;
	std::string PlaceAt;
	bool moved;
public:
	void validmoves();
	void attackSquares();
	void captureFreeMoves();
	bool toBECaptured();
};


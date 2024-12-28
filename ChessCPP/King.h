#pragma once
#include "stdafx.h"

class King : public Piece
{
private:

public:
	King(Color color);
	bool validmoves(std::string currPositon, std::string goalPosition, Piece* (&grid)[8][8]) override;
	void attackSquares(std::string currPositon, std::string goalPosition) override;
	void captureFreeMoves() override;
	bool toBECaptured() override;
	bool checkCheck(Color color);
};


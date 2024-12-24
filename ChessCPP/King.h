#pragma once
#include "stdafx.h"

class King : public Piece
{
private:

public:
	bool validmoves(std::string currPositon, std::string goalPosition) override;
	void attackSquares(std::string currPositon, std::string goalPosition) override;
	void captureFreeMoves() override;
	bool toBECaptured() override;
};


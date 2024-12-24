#pragma once
#include "Piece.h"
#include "stdafx.h"

class Rook : public Piece
{
private:

public:
	Rook(bool color);
	bool validmoves(std::string currPositon, std::string goalPosition) override;
	void attackSquares(std::string currPositon, std::string goalPosition) override;
	void captureFreeMoves() override;
	bool toBECaptured() override;


};


#pragma once
#include "Piece.h"
#include "stdafx.h"

class Pawn : public Piece
{
protected:
	bool _promoted;
	Piece* _promotedTo;
	bool _moveDirection; //true = up //false = down

public:
	Pawn(bool color);
	bool validmoves(std::string currPositon, std::string goalPosition) override;
	void attackSquares(std::string currPositon, std::string goalPosition) override;
	void captureFreeMoves() override;
	bool toBECaptured() override;
};


#pragma once
#include "Piece.h"

class Pawn : public Piece
{
protected:
	bool promoted;
	Piece* promotedTo;
	bool moveDirection; //true = up //false = down

public:
	Pawn(bool color);
	void validmoves() override;
	void attackSquares() override;
	void captureFreeMoves() override;
	bool toBECaptured() override;
};


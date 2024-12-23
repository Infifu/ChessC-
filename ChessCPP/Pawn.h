#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:

public:
	bool promoted();
	Piece* promotedTo();
	bool moveDirection();
	void validmoves() override;
	void attackSquares() override;
	void captureFreeMoves() override;
	bool toBECaptured() override;
	
};


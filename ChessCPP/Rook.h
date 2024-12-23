#pragma once
#include "Piece.h"
class Rook : public Piece
{
private:

public:
	void validmoves() override;
	void attackSquares() override;
	void captureFreeMoves() override;
	bool toBECaptured() override;


};


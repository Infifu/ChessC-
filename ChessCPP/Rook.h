#pragma once
#include "Piece.h"
#include "stdafx.h"

class Rook : public Piece
{
private:

public:
	//constructor for the rook piece
	Rook(bool color);
	
	//function to check if the rook movment is valid
	bool validmoves(std::string currPositon, std::string goalPosition,Piece* (&grid)[8][8]); //add the override later ***

	//TO FINISH:
	void attackSquares(std::string currPositon, std::string goalPosition) override;
	void captureFreeMoves() override;
	bool toBECaptured() override;
};


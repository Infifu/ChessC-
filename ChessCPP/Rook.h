#pragma once
#include "Piece.h"
#include "stdafx.h"

class Rook : public Piece
{
private:

public:
	//constructor for the rook piece
	Rook(Color color);
	
	//function to check if the rook movment is valid
	bool validmoves(std::string currPositon, std::string goalPosition,Piece* (&grid)[8][8]) override; //add the override later ***
};


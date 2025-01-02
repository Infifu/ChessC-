#pragma once
#include "Piece.h"
#include "Board.h"
#include "stdafx.h"

class Knight : public Piece
{
public:

	Knight(Color color); //Knight constructor
	bool validmoves(std::string currPosition, std::string goalPosition, Piece* (&grid)[8][8]); //valid move checker for knight
	
};


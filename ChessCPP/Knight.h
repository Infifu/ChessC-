#pragma once
#include "Piece.h"
#include "Board.h"
#include "stdafx.h"

class Knight : public Piece
{
public:

	Knight(Color color);
	bool validmoves(std::string currPosition, std::string goalPosition, Piece* (&grid)[8][8]);
	
};


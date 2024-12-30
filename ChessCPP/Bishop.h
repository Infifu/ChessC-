#pragma once
#include "Piece.h"
#include "Board.h"
#include "stdafx.h"

class Bishop : public Piece
{
public:
	Bishop(Color color);
	bool validmoves(std::string currPosition, std::string goalPosition, Piece* (&grid)[8][8]);
};


#pragma once
#include "stdafx.h"

class King : public Piece
{
private:

public:
	King(Color color); //king constructor
	bool validmoves(std::string currPositon, std::string goalPosition, Piece* (&grid)[8][8]) override; //valid move for king checker
};


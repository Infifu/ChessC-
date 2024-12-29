#pragma once
#include "stdafx.h"

class King : public Piece
{
private:

public:
	King(Color color);
	bool validmoves(std::string currPositon, std::string goalPosition, Piece* (&grid)[8][8]) override;
};


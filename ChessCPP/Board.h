#pragma once
#include "Piece.h"
#include <iostream>
#include <map>

class Board
{
protected:
	Piece* grid[8][8];
	std::map <std::string, std::string> dict;
public:
	Board();
	void display();
	void intialise();
	bool movePiece(int fromX, int fromY, int toX, int toY);
};


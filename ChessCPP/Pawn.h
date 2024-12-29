#pragma once
#include "Piece.h"
#include "stdafx.h"

enum Direction {
	UP,
	DOWN
};

class Pawn : public Piece
{
protected:
	bool _promoted;
	Piece* _promotedTo;
	Direction _moveDirection;
	bool _firstMove;
public:
	//constructor
	Pawn(Color color);
	
	//function to check if the move is valid
	bool validmoves(std::string currPositon, std::string goalPosition, Piece* (&grid)[8][8]) override;
};


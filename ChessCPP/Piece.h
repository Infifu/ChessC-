#pragma once
#include <iostream>

class Piece
{
protected:
	bool _pieceColor; //field to store the piece color
	std::string _placeAt; //stores position //UNFINISHED
	std::string _pieceSymbol; //Symbol of the pieces (for example P for rook)

public:
	Piece(bool color); //black = false, white = true
	virtual	bool validmoves(std::string currPositon, std::string goalPositionm,Piece* (&grid)[8][8]) = 0;

	//to finish:
	virtual void attackSquares(std::string currPositon, std::string goalPosition) = 0;
	virtual void captureFreeMoves() = 0;
	virtual bool toBECaptured() = 0;
	
	//geters
	std::string getPieceSymbol() const;
	bool getPieceColor() const;
};


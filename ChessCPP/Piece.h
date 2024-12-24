#pragma once
#include <iostream>

class Piece
{
protected:
	bool _pieceColor;
	std::string _placeAt;
	std::string _pieceSymbol;
public:
	Piece(bool color); //black = false, white = true
	std::string getPieceSymbol() const;
	virtual	bool validmoves(std::string currPositon, std::string goalPosition) = 0;
	virtual void attackSquares(std::string currPositon, std::string goalPosition) = 0;
	virtual void captureFreeMoves() = 0;
	virtual bool toBECaptured() = 0;
	bool getPieceColor();
};


#include "Rook.h"

/**
 * Rook constructor,Big 'R' for white rook Small 'r' for black rook (color true = white, color false = black)
 * @param color - bool
 */
Rook::Rook(Color color) : Piece(color)
{
	if (color)
	{
		_pieceSymbol = "R"; //white rook
	}
	else
	{
		_pieceSymbol = "r"; //black rook
	}
}

/**
 * @brief this function checks valid moves for rook, it checks if there is another pieces in the way 
 * @param currPositon - current piece position
 * @param goalPosition - position of the goal piece
 * @param grid that stores all the pieces, to check if there is pieces that block the movment of our rook
 * @return true - valid movie , false - NOT valid move
 */
bool Rook::validmoves(std::string currPositon, std::string goalPosition,Piece* (&grid)[8][8])
{
	int currRow = currPositon[0] - '0'; //convert the row position from char to int
	int currCol = currPositon[1] - '0'; //convert the col position from char to int

	int goalRow = goalPosition[0] - '0'; //convert the goal row position from char to int
	int goalCol = goalPosition[1] - '0';//convert the goal col position from char to int

	//checks if the movement is on the same row or on the same col
	if (currRow == goalRow) //if its on the same row
	{
		for (int i = currCol + 1; i < goalCol; i++) //check for pieces that can block the way
		{
			if (grid[goalRow][i] != nullptr) //if the piece found return false - NOT valid move
			{
				return false;
			}
		}
		return true; //return valid move
	}
	if (currCol == goalCol) //if the movment on the same col
	{
		for (int i = currRow + 1; i < goalRow; i++) //check for pieces that can block the way
		{
			if (grid[i][goalCol] != nullptr)//if the piece foudn return false - Not valid move
			{
				return false;
			}
		}
		return true;
	}
	
	return false;
}

void Rook::attackSquares(std::string currPositon, std::string goalPosition)
{
	//TO DO:
	//Finish
}

void Rook::captureFreeMoves()
{
	//TO DO:
	//FINISH
}

bool Rook::toBECaptured()
{
	//TO DO:
	//FINISH
	return false;
}

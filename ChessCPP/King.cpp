#include "King.h"

/**
 * @brief King construcotr
 * @param color - to what player does the piece belong
 */
King::King(Color color) : Piece(color)
{
	if (color)
	{
		_pieceSymbol = 'K';
	}
	else
	{
		_pieceSymbol = 'k';
	}
}

/**
 * @brief Checking if the move is valid for the Bishop
 * @param currPosition - current position of the bisohp (translated into 2d array locations)
 * @param goalPosition - goal position (translated into 2d array location)
 * @param grid - the board where the magic happens
 * @return true - valid move, false - invalid move
 */
bool King::validmoves(std::string currPositon, std::string goalPosition, Piece* (&grid)[8][8])
{
	int currRow = currPositon[0] - '0'; //convert the row position from char to int
	int currCol = currPositon[1] - '0'; //convert the col position from char to int

	int goalRow = goalPosition[0] - '0'; //convert the goal row position from char to int
	int goalCol = goalPosition[1] - '0';//convert the goal col position from char to int

	if (currRow + 1 == goalRow || currRow - 1 == goalRow || currRow == goalRow)
	{
		if (currCol + 1 == goalCol || currCol - 1 == goalCol || currCol == goalCol)
		{
			return true;
		}
	}
	return false;
}
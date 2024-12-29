#include "King.h"

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
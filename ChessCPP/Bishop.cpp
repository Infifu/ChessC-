#include "Bishop.h"

/**
 * @brief Bishop constructor
 * @param color - player color
 */
Bishop::Bishop(Color color) : Piece(color)
{
	if (color)
	{
		_pieceSymbol = 'B'; //white
	}
	else
	{
		_pieceSymbol = 'b'; //black
	}
}


/**
 * @brief Checking if the move is valid for the Bishop
 * @param currPosition - current position of the bisohp (translated into 2d array locations)
 * @param goalPosition - goal position (translated into 2d array location)
 * @param grid - the board where the magic happens
 * @return true - valid move, false - invalid move
 */
bool Bishop::validmoves(std::string currPosition, std::string goalPosition, Piece* (&grid)[8][8])
{
	int currRow = currPosition[0] - '0'; // Convert the row position from char to int
	int currCol = currPosition[1] - '0'; // Convert the col position from char to int

	int goalRow = goalPosition[0] - '0'; // Convert the goal row position from char to int
	int goalCol = goalPosition[1] - '0'; // Convert the goal col position from char to int

	int j = 0;

	//the whole logic is to check diagonal movement on 4 sides
	if (currRow < goalRow)
	{
		if (currCol < goalCol)
		{
			j = currCol;
			for (int i = currRow; i <= goalRow; i++)
			{
				if (grid[i][j] != nullptr && i != currRow && i != goalRow)
					return false;
				if (j == goalCol && i == goalRow)
				{
					return true;
				}
				j++;
			}
		}
		else
		{
			j = currCol;
			for (int i = currRow; i <= goalRow; i++)
			{	
				if (grid[i][j] != nullptr && i != currRow && i != goalRow)
					return false;
				if (j == goalCol && i == goalRow)
				{
					return true;
				}
				j--;
			}
		}
	}
	else
	{
		j = goalCol;
		if (goalCol < currCol)
		{
			for (int i = goalRow; i <= currRow; i++)
			{	
				if (grid[i][j] != nullptr && i != goalRow && i != currRow)
					return false;
				if (j == currCol && i == currRow) {
					return true;
				}
				j++;
			}
		}
		else
		{
			for (int i = goalRow; i <= currRow; i++)
			{	
				if (grid[i][j] != nullptr && i != goalRow && i != currRow)
					return false;
				if (j == currCol && i == currRow) 
				{
					return true;
				}
				j--;
			}
		}
	}
	return false;
}
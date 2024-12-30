#include "Bishop.h"

Bishop::Bishop(Color color) : Piece(color)
{
	if (color)
	{
		_pieceSymbol = 'B';
	}
	else
	{
		_pieceSymbol = 'b';
	}
}

bool Bishop::validmoves(std::string currPosition, std::string goalPosition, Piece* (&grid)[8][8])
{
	int currRow = currPosition[0] - '0'; // Convert the row position from char to int
	int currCol = currPosition[1] - '0'; // Convert the col position from char to int

	int goalRow = goalPosition[0] - '0'; // Convert the goal row position from char to int
	int goalCol = goalPosition[1] - '0'; // Convert the goal col position from char to int

	int j = 0;
	int startRow = std::min(currRow, goalRow);
	int endRow = std::max(currRow, goalRow);


	if (currRow < goalRow)
	{
		if (currCol < goalCol) {
			j = currCol;
			for (int i = currRow; i <= goalRow; i++) {
				if (grid[i][j] != nullptr && i != currRow && i != goalRow)
					return false;
				if (j == goalCol && i == goalRow) {
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
				if (j == goalCol && i == goalRow) {
					return true;
				}
				j--;
			}
		}
	}
	else
	{
		j = goalCol;
		if (goalCol < currCol) {
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
				if (j == currCol && i == currRow) {
					return true;
				}
				j--;
			}
		}
	}
	return false;
}
#include "Rook.h"


Rook::Rook(bool color) : Piece(color)
{
	if (color)
	{
		_pieceSymbol = "R";
	}
	else
	{
		_pieceSymbol = "r";
	}
}

bool Rook::validmoves(std::string currPositon, std::string goalPosition) {}
//{
//	int currRow = currPositon[0] - '0';
//	int currCol = currPositon[1] - '0';
//
//	int goalRow = goalPosition[0] - '0';
//	int goalCol = goalPosition[1] - '0';
//	
//	if (currRow == goalRow)
//	{
//		for (int i = 0; i < goalRow; i++)
//		{
//			if (board._grid[goalRow][i] != nullptr)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//	if (currCol == goalCol)
//	{
//		for (int i = 0; i < goalCol; i++)
//		{
//			if (board._grid[i][goalCol] != nullptr)
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//	
//	return false;
//}

void Rook::attackSquares(std::string currPositon, std::string goalPosition)
{
	int currRow = currPositon[0] - '0';
	int currCol = currPositon[1] - '0';

	int goalRow = goalPosition[0] - '0';
	int goalCol = goalPosition[0] - '0';

	
}

void Rook::captureFreeMoves()
{
}

bool Rook::toBECaptured()
{
	return false;
}

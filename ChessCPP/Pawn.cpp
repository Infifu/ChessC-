#include "Pawn.h"
#include "Board.h"



/**
 * @brief Pawn constructors, sets the colors symbol and move direction
 * @param color - color of the piece
 */
Pawn::Pawn(Color color) : Piece(color), _promoted(false),_promotedTo(nullptr),_firstMove(true)
{
	if (color) {
		_pieceSymbol = "P";
		_moveDirection = UP;
		_pieceColor = WHITE;
	}
	else {
		_pieceSymbol = "p";
		_moveDirection = DOWN;
		_pieceColor = BLACK;
	}
}


/**
 * @brief check if the move is valid
 * @param currPositon - current position of the figure 
 * @param goalPosition - the target position of the figure
 * @param grid - the chess board
 * @return true - valid move , false - NOT valid move
 */
bool Pawn::validmoves(std::string currPositon, std::string goalPosition, Piece* (&grid)[8][8])
{
	int currRow = currPositon[0] - '0'; //convert the row position from char to int
	int currCol = currPositon[1] - '0'; //convert the col position from char to int

	int goalRow = goalPosition[0] - '0'; //convert the goal row position from char to int
	int goalCol = goalPosition[1] - '0';//convert the goal col position from char to int

	if (currCol == goalCol) //check if the movement is in the same col
	{
		// if the move is by one tile, its a valid move (for white pawn)
		if (_moveDirection == UP && currRow - goalRow == 1)
		{
			return true;
		}
		//if the move is by two tiles check if its the first move of the pawn
		else if (_moveDirection == UP && _firstMove == true && currRow - goalRow == 2)
		{
			_firstMove = false;
			return true;
		}

		// if the move is by one tile, its a valid move (for black pawn)
		if (_moveDirection == DOWN && goalRow - currRow == 1)
		{
			return true;
		}
		//if the move is by two tiles check if its the first move of the pawn
		else if (_moveDirection == DOWN && _firstMove == true && goalRow - currRow == 2)
		{
			_firstMove = false;
			return true;
		}
	}

	return false;
}

#include "Rook.h"

/**
 * Rook constructor,Big 'R' for white rook Small 'r' for black rook (color true = white, color false = black)
 * @param color - bool
 */
Rook::Rook(Color color) : Piece(color)
{
	if (color)
		_pieceSymbol = "R"; //white rook
	else
		_pieceSymbol = "r"; //black rook
}

/**
 * @brief this function checks valid moves for rook, it checks if there is another pieces in the way 
 * @param currPositon - current piece position
 * @param goalPosition - position of the goal piece
 * @param grid that stores all the pieces, to check if there is pieces that block the movment of our rook
 * @return true - valid movie , false - NOT valid move
 */
bool Rook::validmoves(std::string currPosition, std::string goalPosition, Piece* (&grid)[8][8])
{
    int currRow = currPosition[0] - '0'; // Convert the row position from char to int
    int currCol = currPosition[1] - '0'; // Convert the col position from char to int

    int goalRow = goalPosition[0] - '0'; // Convert the goal row position from char to int
    int goalCol = goalPosition[1] - '0'; // Convert the goal col position from char to int

    // Check if the movement is on the same row or on the same column
    if (currRow == goalRow) // If it's on the same row
    {
        int startCol = std::min(currCol, goalCol) + 1;
        int endCol = std::max(currCol, goalCol);
        for (int i = startCol; i < endCol; ++i) // Check for pieces that can block the way
        {
            if (grid[currRow][i] != nullptr) // If a piece is found, return false - NOT a valid move
            {
                return false;
            }
        }
        return true; // Return valid move
    }
    else if (currCol == goalCol) // If the movement is on the same column
    {
        int startRow = std::min(currRow, goalRow) + 1;
        int endRow = std::max(currRow, goalRow);
        for (int i = startRow; i < endRow; ++i) // Check for pieces that can block the way
        {
            if (grid[i][currCol] != nullptr) // If a piece is found, return false - NOT a valid move
            {
                return false;
            }
        }
        return true; // Return valid move
    }
    return false; // Not a valid move if it's not in the same row or column
}

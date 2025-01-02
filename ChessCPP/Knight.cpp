#include "Knight.h"

/**
 * @brief Knight constructor
 * @param color - to which player does the knight belong to
 */
Knight::Knight(Color color) : Piece(color)
{
    if (color)
    {
        _pieceSymbol = "N";
    }
    else
    {
        _pieceSymbol = "n";
    }

}


/**
 * @brief Checking if the move is valid for the Knight
 * @param currPosition - current position of the Knight (translated into 2d array locations)
 * @param goalPosition - goal position (translated into 2d array location)
 * @param grid - the board where the magic happens
 * @return true - valid move, false - invalid move
 */
bool Knight::validmoves(std::string currPosition, std::string goalPosition, Piece* (&grid)[8][8])
{
    int currRow = currPosition[0] - '0'; // Convert the row position from char to int
    int currCol = currPosition[1] - '0'; // Convert the col position from char to int

    int goalRow = goalPosition[0] - '0'; // Convert the goal row position from char to int
    int goalCol = goalPosition[1] - '0'; // Convert the goal col position from char to int

    if ((currCol + 2 == goalCol && (currRow + 1 == goalRow || currRow - 1 == goalRow)) ||
        (currCol - 2 == goalCol && (currRow + 1 == goalRow || currRow - 1 == goalRow)) ||
        (currRow + 2 == goalRow && (currCol + 1 == goalCol || currCol - 1 == goalCol)) ||
        (currRow - 2 == goalRow && (currCol + 1 == goalCol || currCol - 1 == goalCol)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

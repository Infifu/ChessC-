#include "Queen.h"
#include "stdafx.h"

Queen::Queen(Color color) : Piece(color)
{
    if (color)
    {
        _pieceSymbol = "Q";
    }
    else
    {
        _pieceSymbol = "q";
    }
}


bool Queen::validmoves(std::string currPosition, std::string goalPosition, Piece* (&grid)[8][8])
{
    int currRow = currPosition[0] - '0'; //convert the row position from char to int
    int currCol = currPosition[1] - '0'; //convert the col position from char to int

    int goalRow = goalPosition[0] - '0'; //convert the goal row position from char to int
    int goalCol = goalPosition[1] - '0';//convert the goal col position from char to int

    Bishop bishop(_pieceColor);
    Rook rook(_pieceColor);
    King king(_pieceColor);

    if (bishop.validmoves(currPosition, goalPosition, grid) || rook.validmoves(currPosition, goalPosition, grid) || king.validmoves(currPosition, goalPosition, grid))
    {
        return true;
    }
    return false;
}


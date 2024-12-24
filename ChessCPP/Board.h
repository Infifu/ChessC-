#pragma once
#include "Piece.h"
#include <iostream>
#include <map>

class Board
{
protected:
    Piece* _grid[8][8];
    std::map<std::string, std::string> _dict;
public:
    Board();
    void display();
    void intialise();
    bool movePiece(int fromX, int fromY, int toX, int toY);
    std::string indexToNumber(std::string);
    int checkMove(std::string msgFromGraphics);
};
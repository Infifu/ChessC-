#pragma once
#include "Piece.h"
#include <iostream>
#include <map>

class Board
{
protected:
    Piece* _grid[8][8];
    std::map<std::string, std::string> _dict; //might be deleted later
public:
    Board(); //constructor
    void display(); //display the board
    void intialise(); //initalise the grid with chess pieces
    bool movePiece(int fromX, int fromY, int toX, int toY); //might be deleted later
    std::string indexToNumber(std::string); //convert the chess position to 2d array position
    int checkMove(std::string msgFromGraphics); //check if the move is valid and return codes
};
#pragma once
#include "Piece.h"
#include <iostream>
#include <map>

enum checkStatus
{
    null = 0,
    onWhite = 1,
    onBlack = 2
};

class Board
{
protected:
    Piece* _grid[8][8];
    Color _currentPlayer;
    checkStatus _checkOnKing;
public:
    Board(Color color); //constructor
    void display(); //display the board
    void intialise(); //initalise the grid with chess pieces
    bool movePiece(int fromX, int fromY, int toX, int toY); //might be deleted later
    std::string indexToNumber(std::string); //convert the chess position to 2d array position
    int checkMove(std::string msgFromGraphics); //check if the move is valid and return codes
    bool checkCheck(Color currentPlayer); //check if there is a check on the enemy king
    void switchColor(); //switch current player color
};
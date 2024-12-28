#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "stdafx.h"
#include <iostream>
#include <string>

/**
 * @brief Fill the grid with null pointers
 */
Board::Board(Color color) : _currentPlayer(color)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			_grid[i][j] = nullptr;
		}
	}
}

/**
 * @brief print the grid for debugging
 */
void Board::display()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (_grid[i][j] != nullptr)
			{
				std::cout << _grid[i][j]->getPieceSymbol() << " ";
			}
			else
			{
				std::cout << "# ";
			}
		}
		std::cout << std::endl;
	}
}

/*
* Initialise the grid with all the pieces
*/
void Board::intialise()
{
	//black = false, white = true
	for (int j = 0; j < 8; j++)
	{
		_grid[6][j] = new Pawn(WHITE); //white white pawns
		_grid[1][j] = new Pawn(BLACK); //black pawns
	}

	//Rooks
	_grid[7][0] = new Rook(WHITE);
	_grid[7][7] = new Rook(WHITE);
	_grid[0][0] = new Rook(BLACK);
	_grid[0][7] = new Rook(BLACK);

	//Kings
	_grid[0][3] = new King(BLACK);
	_grid[7][3] = new King(WHITE);

	//TO DO
	//Add other pieces
}

bool Board::movePiece(int fromX, int fromY, int toX, int toY)
{
	//TO DO
	//Do we even need this function?
	return false;
}


// [][]
// row col                                      e2
/**
 * @brief this functions converts chess position into 2d array position
 * for example for e2 position it will become 64 6 - row, 4 - col
 * @param location on the chess board for example (e2)
 * @return the string that contains the 2d array position
 */                                          
std::string Board::indexToNumber(std::string location)
{
	std::string result;
	int chessNumbers[8] = {7,6,5,4,3,2,1,0};
	char letter = location[0];
	int letterInt = letter - 'a';
	int number = location[1] - '0' - 1;
	number = chessNumbers[number];
	result = std::to_string(number); //row
	result += std::to_string(letterInt); //col
	return result;
}




/**
 * @brief This function checks if the move is valid outside of the standart rules for each piece
 * @param msgFromGraphics (2 positions on the chess board , from and to)
 * @return the code to the graphics
 */
int Board::checkMove(std::string msgFromGraphics)
{
	//declaring all the variables
	std::string from;
	std::string to;
	std::string result;
	std::string resultTo;
	Piece* fromPiece;
	Piece* toPiece;
	int FromRow;
	int ToRow;
	int FromCol;
	int ToCol;

	//strings that hold the chess board position of from figure and target figure
	from += msgFromGraphics[0];
	from += msgFromGraphics[1];
	to += msgFromGraphics[2];
	to += msgFromGraphics[3];

	//convert these chess board positions into 2d array positions
	result = indexToNumber(from);
	resultTo = indexToNumber(to);
	FromRow = int(result[0]) - 48;
	ToRow = int(resultTo[0]) - 48;
	FromCol = int(result[1]) - 48;
	ToCol = int(resultTo[1]) - 48;

	fromPiece = _grid[FromRow][FromCol];
	toPiece = _grid[ToRow][ToCol];

	if (fromPiece == nullptr)
		return 2; //error if the the player choose position without piece

	if (fromPiece->getPieceColor() != _currentPlayer)
		return 6;

	if (fromPiece->validmoves(result, resultTo, _grid)) { //if the goal is empty and there is no pieces blocking it
		if (toPiece != nullptr) {
			if (toPiece->getPieceSymbol() == "k" || toPiece->getPieceSymbol() == "K")
				return 6;
		}
		_grid[FromRow][FromCol] = nullptr; //move the pieces
		_grid[ToRow][ToCol] = fromPiece;
		delete(toPiece);

		if (checkCheck(_currentPlayer))
			return 1; //code for check

		return 0; //code for valid move
	}

	if (fromPiece != nullptr && toPiece != nullptr) {
		if (fromPiece->getPieceColor() == toPiece->getPieceColor())
			return 3; //error if both figures belong to the same player figures
	}

	return 6; //error for invalid piece movement
}

/**
 * @brief functions to check if there is a check on the king
 * @param currentPlayer - the color of the current player
 * @return true - there is a check, false - there is no check
 */
bool Board::checkCheck(Color currentPlayer)
{
	std::string currPosition;
	std::string goalPosition;
	bool found;

	//loop though the board to find the enemy king
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (_grid[i][j] != nullptr) {
				if (_grid[i][j]->getPieceColor() != currentPlayer) {
					if (_grid[i][j]->getPieceSymbol() == "k" || _grid[i][j]->getPieceSymbol() == "K") {
						goalPosition = std::to_string(i) + std::to_string(j);
						break;
					}
				}
			}
		}
	}

	//check if any figure threats the enemy king
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (_grid[i][j] != nullptr) {
				if (_grid[i][j]->getPieceColor() == currentPlayer) {
					currPosition.clear();
					currPosition = std::to_string(i) + std::to_string(j);
					if (_grid[i][j]->validmoves(currPosition, goalPosition, _grid))
						return true;
				}
			}
		}
	}
	return false;
}

/**
 * @brief switch the color of the current player
 */
void Board::switchColor()
{
	if (_currentPlayer == WHITE)
		_currentPlayer = BLACK;
	else if (_currentPlayer == BLACK)
		_currentPlayer = WHITE;
}


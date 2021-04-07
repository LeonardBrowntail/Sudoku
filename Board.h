#pragma once
#include "Loader.h"
constexpr auto BOARD_SQRT = 3;

class Board
{
private:
	int cell[BOARD_SIZE][BOARD_SIZE] = {};
	Loader sol;
	bool isFull;
public:
	Board();
	void CreateHints(int);
	void SetCell(int, int, int);
	void DelCell(int, int);
	bool IsFull();
	void DrawBoard();
};

//Constructor
Board::Board()
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			cell[x][y] = 0;
		}
	}
	isFull = 0;
}

//Create hints based on the difficulty
void Board::CreateHints(int dif)
{
	int rep = 24 / dif;
	std::random_device gen;
	std::uniform_int_distribution<int> dist(0, 8);
	for (int i = 0; i < rep; i++)
	{
		int xi = dist(gen);
		int yi = dist(gen);
		cell[xi][yi] = sol.grid[xi][yi];
	}
}

//Set cell with x and y coordinate with input
void Board::SetCell(int x, int y, int input)
{
	cell[x][y] = input;
}

//Delete cell
void Board::DelCell(int x, int y)
{
	cell[x][y] = 0;
}

//Detect if board is full
bool Board::IsFull()
{
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (cell[x][y] == 0)
				return false;
		}
	}
	return true;
}

//Draw the board
void Board::DrawBoard()
{
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			std::cout << cell[x][y];
		}
		std::cout << std::endl;
	}
}
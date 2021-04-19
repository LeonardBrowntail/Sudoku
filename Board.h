/*==================================================================*/
/* Header file is written by: Aydin Ihsan Ibrahim Nurdin 4210191004 */
/*==================================================================*/
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
	/* Constructor */
	Board();

	/* Setter */
	void SetCell(int, int, int);

	/* Getter */
	int GetCell(int, int);
	bool IsFull();

	/* Other Functions */
	void CreateHints(int);
	void DelCell(int, int);
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

//Set cell with x - 1 and y - 1 coordinate with input
void Board::SetCell(int x, int y, int input)
{
	cell[x - 1][y - 1] = input;
}

//Delete cell at x-1 and y-1
void Board::DelCell(int x, int y)
{
	cell[x - 1][y - 1] = 0;
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

//Get a value inside a cell
int Board::GetCell(int x, int y)
{
	return cell[x][y];
}

//Draw the board
void Board::DrawBoard()
{
	//Repeat three times
	for (int i = 1; i <= 3; i++)
	{
		for (int y = BOARD_SQRT * (i - 1); y < BOARD_SQRT * i; y++)
		{
			for (int x = 0; x < BOARD_SIZE; x++)
			{
				if (x == BOARD_SQRT || x == BOARD_SQRT * 2)
				{
					std::cout << " | " << cell[x][y];
				}
				else
				{
					std::cout << cell[x][y];
				}
			}
			std::cout << std::endl;
		}
		std::cout << "===============\n";
	}
}
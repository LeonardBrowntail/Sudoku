#pragma once
#include "Board.h"
#include "Player.h"

class GameManager
{
private:
	Board board = Board();
	Player player;
	int difficulty;
	bool playing;
public:
	GameManager();
	void Start();
	void PlayerMove();
	bool DetectWin();
};

//Constructor
GameManager::GameManager()
{
	playing = true;
	std::cout << "1 - easy, 2 - medium, 3 - hard\nPlease choose the difficulty: ";
	std::cin >> difficulty;
}

//Start the game
void GameManager::Start()
{
	board.CreateHints(difficulty);
	while (playing)
	{
		//Draw the board
		board.DrawBoard();

		//Player moves
		PlayerMove();

		//Detect if board is full
		if (DetectWin())
		{
			playing = false;
		}
	}
	//Win statement
}

//Player input to the board
void GameManager::PlayerMove()
{
	char in;
	std::cout << "\nPress 1-9 to insert an x coordinate, z to undo, r to redo\n";
	std::cout << "Input: ";
	std::cin >> in;

	/*Keyboard input*/
	//Undo
	if (in == 'z')
	{
		//TODO: implement undo function
		std::cout << "Unimplemented yet!\n";
	}
	//Redo
	else if (in == 'r')
	{
		//TODO: implement redo function
		std::cout << "Unimplemented yet!\n";
	}
	//Input
	else if (in > '0' && in <= '9')
	{
		//get x coord
		int x = in - '0';
		fflush(stdin);
		std::cout << "Input y coord (enter q to cancel): ";
		std::cin >> in;
		if (in > '0' && in <= '9')
		{
			int y = in - '0';
			while (true)
			{
				fflush(stdin);
				std::cout << "Input the number you wish to put in: ";
				std::cin >> in;

				if (in == '')
			}
		}
	}
	//Invalid input
	else
	{
		std::cout << "Invalid input...\n";
	}
}

//Detect if board is full
bool GameManager::DetectWin()
{
	return board.IsFull();
}
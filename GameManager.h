/*==================================================================*/
/* Header file is written by: Aydin Ihsan Ibrahim Nurdin 4210191004 */
/*==================================================================*/
#pragma once
#include "Board.h"
#include "Player.h"
#include "Invoker.h"

class GameManager
{
private:
	Board board;
	Player player;
	Invoker invoker;
	int difficulty;
	bool playing;
public:
	GameManager();
	void Play();
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
void GameManager::Play()
{
	board.CreateHints(difficulty);
	while (playing)
	{
		//Detect if board is full
		if (DetectWin())
		{
			playing = false;
		}
		system("cls");
		//Draw the board
		board.DrawBoard();

		//Player moves
		PlayerMove();
	}
}

//Player input to the board
void GameManager::PlayerMove()
{
	char in;
	std::cout << "\nPress q to quit the game...\n1. Fill a cell\n2. Delete a cell\n3. Undo\n4. Redo\n5. Refresh board\nInput: ";
	std::cin >> in;

	/* Fill a cell */
	if (in == '1')
	{
		fflush(stdin);
		std::cout << "\nPlease input the x-coordinate: ";
		int x = 0;
		std::cin >> x;

		fflush(stdin);
		std::cout << "\nPlease input the y-coordinate: ";
		int y = 0;
		std::cin >> y;

		fflush(stdin);
		std::cout << "\nPlease input the value: ";
		int val;
		std::cin >> val;

		Command* command = new FillCell(x, y, val, board);
		command->Execute();
		invoker.PushCommand(*command);
	}
	/* Delete a Cell */
	else if (in == '2')
	{
		fflush(stdin);
		std::cout << "\nPlease input the x-coordinate: ";
		int x = 0;
		std::cin >> x;

		fflush(stdin);
		std::cout << "\nPlease input the y-coordinate: ";
		int y = 0;
		std::cin >> y;

		Command* command = new DeleteCell(x, y, board);
		command->Execute();
		invoker.PushCommand(*command);
	}
	/* Undo */
	else if (in == '3')
	{
		if (!invoker.UndoAction())
		{
			std::cout << "Undo unsuccessful, stack is empty...";
		}
	}
	/* Redo */
	else if (in == '4')
	{
		if (!invoker.RedoAction())
		{
			std::cout << "Redo unsuccessful, stack is empty...";
		}
	}
	else if (in == '5')
	{
		board.DrawBoard();
	}
	else if (in == 'q')
	{
		system("cls");
		std::cout << "Quiting so soon?... Take care then c:";
		exit(0);
	}
	else
	{
		std::cout << "Invalid option!\n";
	}
}

//Detect if board is full
bool GameManager::DetectWin()
{
	return board.IsFull();
}
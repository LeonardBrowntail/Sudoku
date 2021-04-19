/*==================================================================*/
/* Header file is written by: Aydin Ihsan Ibrahim Nurdin 4210191004 */
/*==================================================================*/
#pragma once
constexpr auto BOARD_SIZE = 9;
class Loader
{
private:
	int fileNum;
public:
	int grid[9][9] = {};
	Loader();
	void LoadAnswer();
};

//Constructor
#include <random>
Loader::Loader()
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			grid[x][y] = 0;
		}
	}
	std::random_device gen;
	std::uniform_int_distribution<int> dist(1, 10);

	fileNum = dist(gen);

	LoadAnswer();
}

//Load a solution from 10 different solutions
#include <iostream>
#include <fstream>
#include <string>
void Loader::LoadAnswer()
{
	//Create file name to be opened
	std::string fileName;
	fileName = "./Solution/" + std::to_string(fileNum) + ".sol";

	//Opening solution file
	std::ifstream file;
	file.open(fileName, std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Unable to find solution file, aborting!";
		exit(-1);
	}
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			std::string temp;
			std::getline(file, temp);
			if (!temp.empty())
			{
				grid[x][y] = temp[0] - '0';
			}
		}
	}
}
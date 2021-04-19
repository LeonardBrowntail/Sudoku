/*==============================================*/
/* Code is written by: Prawida Yumia 4210191005 */
/*==============================================*/
#pragma once
#include <string>

class Player
{
private:
	std::string name;
	int score;
public:
	Player();
	void SetName(std::string);
	void SetScore(int);
	std::string GetName();
	int GetScore();
};

//Constructor
Player::Player()
{
	name = "";
	score = 0;
}

//Setting player name based on parameter
void Player::SetName(std::string inputName)
{
	name = inputName;
}

//Inputting player's score
void Player::SetScore(int inputScore)
{
	score = inputScore;
}

//Get player's name
std::string Player::GetName()
{
	return name;
}

//Get player's score
int Player::GetScore()
{
	return score;
}
#pragma once

#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Coin.h"

using std::vector;


class GameController
{
public:
	GameController();
	void run();
	void ReadBoard();

private:
	vector <std::string> m_board;
	int m_score = 0;
	int m_level = 0;
	vector <Coin> m_coins;
	vector <Enemy> m_enemies;
	Player m_player;

	void printBoard();
	void movePlayer();

	bool isFloor(char c);
	bool isValid(char c);

	// void handleSpecialKey();

};
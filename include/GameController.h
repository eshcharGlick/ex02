#pragma once

#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Coin.h"

const int NUM_OF_LEVELS = 2 ;

using std::vector;


class GameController
{
public:
	GameController() {}
	void run();
	void ReadBoard();

private:
	vector <std::string> m_board;
	int m_score = 0;
	int m_level = 0;
	vector <Coin> m_coins;
	vector <Enemy> m_enemies;
	Player m_player;
	int m_size;


	void runLevel(int level);

	void printBoard();
	void movePlayer();
	int checkConsequences();

	bool isFloor(char c);
	bool isValid(char c);

	// void handleSpecialKey();

};
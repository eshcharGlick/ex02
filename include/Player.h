#pragma once

#define NUM_OF_LIVES 3 ;

class Player
{
public:
	Player(int xCord , int yCord);

	int get_X();
	int get_Y();
		
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	bool dead();

private:
	int m_lives = NUM_OF_LIVES;
	int m_xCord;
	int m_yCord;
};
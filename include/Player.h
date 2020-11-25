#pragma once

#include <Vertex.h>
const int NUM_OF_LIVES = 3 ;

class Player
{
public:
	Player() {}
	Player(Location loc);

	Location getLocation();
		
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	int getLives();
	void dead();

private:
	int m_lives = NUM_OF_LIVES;
	Location m_currLoc;
	Location m_startLoc;
};
#pragma once

#include <Vertex.h>
const int NUM_OF_LIVES = 3 ;

class Player
{
public:
	Player() {}
	Player(Vertex cord);

	Vertex getVertex();
		
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	int getLives();
	void dead();

private:
	int m_lives = NUM_OF_LIVES;
	Vertex m_currCord;
	Vertex m_startCord;
};
#pragma once
#include <Vertex.h>


class Enemy
{
public:
	Enemy(Location cord);

	Location getLocation();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void restart();

private:
	Location m_currLoc;
	Location m_startLoc;
};

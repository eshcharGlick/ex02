#pragma once
#include <Vertex.h>


class Enemy
{
public:
	Enemy() : m_currCord(Vertex(0, 0)) ,m_startCord(Vertex(0, 0)) {}
	Enemy(Vertex cord);

	Vertex getVertex();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void restart();

private:
	Vertex m_currCord;
	Vertex m_startCord;
};

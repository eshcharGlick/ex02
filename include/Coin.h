#pragma once
#include <Vertex.h>

class Coin
{
public:
	Coin(Vertex cord);
	Vertex getVertex();
	void picked();

private:

	Vertex m_cord;

};
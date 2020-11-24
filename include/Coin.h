#pragma once
#include <Vertex.h>

class Coin
{
public:
	Coin () : m_cord (Vertex (0 ,0)) {}
	Coin(Vertex cord);
	Vertex getVertex();
	void picked();

private:

	Vertex m_cord;

};
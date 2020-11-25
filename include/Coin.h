#pragma once
#include <Vertex.h>

class Coin
{
public:
	Coin(Location cord);
	Location getLocation();
	void picked();

private:

	Location m_cord;

};
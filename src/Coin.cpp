#include "Coin.h"

Coin::Coin(Vertex cord)
{
	m_cord = cord;
}

Vertex Coin::getVertex()
{
	return m_cord;
}

void Coin::picked()
{
	delete this;
}
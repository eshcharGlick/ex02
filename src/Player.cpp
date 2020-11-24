#include "Player.h"


Player::Player(Vertex cord)
{
	m_currCord = m_startCord = cord;
}

Vertex Player::getVertex()
{
	return m_currCord;
}

void Player::moveUp()
{
	m_currCord.m_row--;
}

void Player::moveDown()
{
	m_currCord.m_row++;
}

void Player::moveRight()
{
	m_currCord.m_col++;
}

void Player::moveLeft()
{
	m_currCord.m_col--;
}

int Player::getLives()
{
	return m_lives;
}


void Player::dead()
{
	m_lives -- ;
	m_currCord = m_startCord;
}

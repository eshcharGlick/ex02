#include "Player.h"


Player::Player(Location loc)
{
	m_currLoc = m_startLoc = loc;
}

Location Player::getLocation()
{
	return m_currLoc;
}

void Player::moveUp()
{
	m_currLoc.m_row--;
}

void Player::moveDown()
{
	m_currLoc.m_row++;
}

void Player::moveRight()
{
	m_currLoc.m_col++;
}

void Player::moveLeft()
{
	m_currLoc.m_col--;
}

int Player::getLives()
{
	return m_lives;
}


void Player::dead()
{
	m_lives -- ;
	m_currLoc = m_startLoc;
}

#include "Player.h"


Player::Player(int xCord, int yCord)
{
	m_xCord = xCord;
	m_yCord = yCord;
}

int Player::get_X()
{
	return m_xCord;
}

int Player::get_Y()
{
	return m_yCord;
}

void Player::moveUp()
{
	m_yCord++;
}

void Player::moveDown()
{
	m_yCord--;
}

void Player::moveRight()
{
	m_xCord++;
}

void Player::moveLeft()
{
	m_xCord--;
}


bool Player::dead()
{
	m_lives -- ;
	if (m_lives > 0)
		return false;
	return true;
}

#include "Enemy.h"

Enemy::Enemy(Vertex cord)
{
	m_currCord = m_startCord = cord;
}

Vertex Enemy::getVertex()
{
	return m_currCord;
}

void Enemy::moveUp()
{
	m_currCord.m_row--;
}

void Enemy::moveDown()
{
	m_currCord.m_row++;
}

void Enemy::moveRight()
{
	m_currCord.m_col++;
}

void Enemy::moveLeft()
{
	m_currCord.m_col--;
}

void Enemy::restart()
{
	m_currCord = m_startCord;
}
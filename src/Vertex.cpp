#include "..\include\Vertex.h"
#include "..\include\Vertex.h"
#include "Vertex.h"
// #include "macros.h"

#include <iostream>

bool Vertex::same(Vertex other)
{
    if (this->m_col == other.m_col && this->m_row == other.m_row)
}

bool Vertex::isHigherThan(const Vertex& other) const
{
    return m_row > other.m_row;
}

bool Vertex::isToTheRightOf(const Vertex& other) const
{
    return m_col > other.m_col;
}

bool Vertex::sameRow(const Vertex& other) const
{
    return this->m_row == other.m_row;
}

bool Vertex::sameCol(const Vertex& other) const
{
    return this->m_col == other.m_col;
}

std::istream& operator>>(std::istream& istr, Vertex& v)
{
    return istr >> v.m_col >> v.m_row;
}

std::ostream& operator<<(std::ostream& ostr, const Vertex& v)
{
    return ostr << "(" << v.m_col << ", " << v.m_row << ")";
}

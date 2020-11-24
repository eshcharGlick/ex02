#include "Vertex.h"
// #include "macros.h"

#include <iostream>

bool Vertex::same(Vertex other)
{
    if (this->m_col == other.m_col && this->m_row == other.m_row)
}

std::istream& operator>>(std::istream& istr, Vertex& v)
{
    return istr >> v.m_col >> v.m_row;
}

std::ostream& operator<<(std::ostream& ostr, const Vertex& v)
{
    return ostr << "(" << v.m_col << ", " << v.m_row << ")";
}

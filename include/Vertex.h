#pragma once

#include <iosfwd>

struct Vertex
{
    double m_col = 0; // x
    double m_row = 0; // y

    Vertex() = default;
    Vertex( double row, double col) : m_col(col), m_row(row) {}

    bool isHigherThan(const Vertex& other) const;
    bool isToTheRightOf(const Vertex& other) const;
    bool sameRow(const Vertex& other) const;
    bool sameCol(const Vertex& other) const;
    bool same(Vertex other);
    
};

std::istream& operator>>(std::istream& istr, Vertex& v);
std::ostream& operator<<(std::ostream& ostr, const Vertex& v);

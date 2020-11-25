#include <Location.h>

bool Location::same(Location other)
{
	return this->row == other.row && this->col == other.col;
}

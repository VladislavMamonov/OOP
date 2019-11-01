#include "set.hpp"

List::~List()
{
	clear();
}

void List::clear()
{
	while (Size > 0) {
    pop();
	}
}

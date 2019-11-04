#include "set.hpp"

List::~List()
{
	clear();
}


void List::clear()
{
	while (this->Size > 0) {
    pop();
	}
}

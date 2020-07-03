#include "mywrapper.h"
#include <iostream>

int mywrapper::get_deque(int get_number)
{
    return d.at(get_number);
}

void mywrapper::pushback_deque(int set_number)
{
    d.push_back(set_number);
}

void mywrapper::pushfront_deque(int set_number)
{
    d.push_front(set_number);
}

void mywrapper::removeback_deque()
{
    d.pop_back();
}


void mywrapper::removefront_deque()
{
    d.pop_front();
}


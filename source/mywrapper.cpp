#include "mywrapper.h"
#include <iostream>

int mywrapper::get_deque(int get_number)
{
   return  d.at(get_number);
}

void mywrapper::set_deque(int set_number)
{
    deque<int>::iterator it = d.begin();
    ++it;

    it = d.insert(it, set_number);
}
#include <iostream>
#include "taskmanager.h"

taskmanager::taskmanager()
{
}
taskmanager::~taskmanager()
{
}

void taskmanager::push_back(function_type_m fun)
{
    //insert
    d.push_back(fun);
}

function_type_m taskmanager::pop_front()
{
    //read and delete
    auto fun =d.front();
    d.pop_front();
    function_type_m f;
    return fun;
}
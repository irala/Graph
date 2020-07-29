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
    std::lock_guard<std::mutex> lck(mtx);
    d.push_back(fun);
}

function_type_m taskmanager::pop_front()
{
     std::lock_guard<std::mutex> lck(mtx);
    //read and delete
    if(d.empty()){
        return nullptr;
    }
    auto fun =d.front();
    d.pop_front();
    function_type_m f;
    return fun;
}

 
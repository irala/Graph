#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <iostream>
#include <deque>
#include <functional>

using std::cout;
using std::deque;
using std::endl;
using std::string;
using function_type_m = std::function<void()>;

class taskmanager
{
public:
    taskmanager();
    virtual ~taskmanager();

    void push_back(function_type_m f);
    function_type_m pop_front();
    static taskmanager & get_manager(){
       static taskmanager manager;
       return manager;
    }

private:
    deque<function_type_m> d;
};
#endif //TASKMANAGER_H
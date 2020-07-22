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

    void pushback(function_type_m f);
    void popback();

private:
    deque<function_type_m> d;
};
#endif //TASKMANAGER_H
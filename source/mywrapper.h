#ifndef MYWRAPPER_H
#define MYWRAPPER_H
#include <iostream>
#include <deque>

using std::cout;
using std::deque;
using std::endl;
using std::string;

class mywrapper
{

public:
    mywrapper() = default;
    virtual ~mywrapper();

private:
    deque<int> d;

    int get_deque(int get_number);
    void set_deque(int set_number);
};

#endif //MYWRAPPER_H

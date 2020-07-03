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

    int get(int get_number);
    void removeback();
    void removefront();
    void pushback(int set_number);
    void pushfront(int set_number);
};

#endif //MYWRAPPER_H

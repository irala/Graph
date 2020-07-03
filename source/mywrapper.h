#ifndef MYWRAPPER_H
#define MYWRAPPER_H
#include <iostream>
#include <deque>

using std::cout;
using std::deque;
using std::endl;
using std::string;

template <typename T>
class mywrapper
{

public:
    mywrapper() = default;
    virtual ~mywrapper();

private:
    deque<T> d;

    int get(T value);
    void removeback();
    void removefront();
    void pushback(T value);
    void pushfront(T value);
};


//start .cpp
template <typename T>

int mywrapper<T>::get(T value)
{
    return d.at(value);
}

template <typename T>

void mywrapper<T>::pushback(T value)
{
    d.push_back(value);
}

template <typename T>

void mywrapper<T>::pushfront(T value)
{
    d.push_front(value);
}

template <typename T>

void mywrapper<T>::removeback()
{
    d.pop_back();
}

template <typename T>

void mywrapper<T>::removefront()
{
    d.pop_front();
}


//end .cpp
#endif //MYWRAPPER_H

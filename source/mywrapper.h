#ifndef MYWRAPPER_H
#define MYWRAPPER_H
#include <iostream>
#include <deque>

#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

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

    int get(T value);
    void removeback();
    void removefront();
    void pushback(T value);
    void pushfront(T value);
    static mywrapper &get_pool();
    boost::asio::io_service ioService;

private:
    deque<T> d;
};

//start .cpp

template <typename T>
mywrapper<T>::~mywrapper()
{
}

template <typename T>
mywrapper<T> &mywrapper<T>::get_pool()
{
    static mywrapper<T> tp;
    return tp;
}

template <typename T>

int mywrapper<T>::get(T value)
{
    return d.at(value);
}

template <typename T>

void mywrapper<T>::pushback(T value)
{
    cout << "pushback " << value << endl;

    d.push_back(value);
}

template <typename T>

void mywrapper<T>::pushfront(T value)
{
    cout << "pushfront " << value << endl;
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

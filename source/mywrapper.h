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
    mywrapper() ;
    virtual ~mywrapper();

    int get(T value);
    void removeback();
    void removefront();
    void pushback(T value);
    void pushfront(T value);
    static mywrapper &get_pool();
    boost::asio::io_service ioService;
    boost::asio::io_service::work work;
	boost::thread_group threadpool;
	int threads;

private:
    deque<T> d;
};

//start .cpp

template <typename T>
mywrapper<T>::mywrapper():work(ioService),threads(1){
    for (size_t i = 0; i < threads ; i++)
    {
        threadpool.create_thread( 
            boost::bind(&boost::asio::io_service::run, &ioService));
    }
    cout << "Thread Pool Created" << endl;

}

template <typename T>
mywrapper<T>::~mywrapper()
{
     ioService.stop();
    threadpool.join_all();
    cout << "Thread Pool Terminated" << endl;
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

#ifndef MYWRAPPER_H
#define MYWRAPPER_H
#include <iostream>
#include <deque>

#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

#include <functional>
#include <thread>
#include <mutex>

using std::cout;
using std::deque;
using std::endl;
using std::string;

using function_type_m = std::function<void()>;

template <typename T>
class mywrapper
{

public:
    mywrapper();
    virtual ~mywrapper();

    int get(T value);
    void removeback();
    void removefront();
    void pushback(T value);
    void pushfront(T value);
    void said_hello();
    static mywrapper &get_pool();
    void get_ioService();
    void addfunction();
    // boost::asio::io_service ioService;
    // boost::asio::io_service::work work;
    // boost::thread_group threadpool;
    int threads;
    deque<function_type_m> d;

private:
    // using  function_type=void (*myfunction)(int);
};

//start .cpp

template <typename T>
mywrapper<T>::mywrapper() //: work(ioService), threads(1)
{
    // for (size_t i = 0; i < threads; i++)
    // {
    //     threadpool.create_thread(
    //         boost::bind(&boost::asio::io_service::run, &ioService));
    // }
    // cout << "Thread Pool Created" << endl;
}

template <typename T>
mywrapper<T>::~mywrapper()
{
    // ioService.stop();
    // threadpool.join_all();
    // cout << "Thread Pool Terminated" << endl;
}

template <typename T>
mywrapper<T> &mywrapper<T>::get_pool()
{
    static mywrapper<T> tp;
    return tp;
}

template <typename T>
void said_hello()
{
    cout << "hello " << endl;
}

template <typename T>
void mywrapper<T>::get_ioService()
{
    // get_pool().ioService.post(boost::bind(&mywrapper<T>::said_hello));
    // for (size_t i = 0; i < 1000; i++)
    // {
    //     /* code */
    //     cout << i << endl;
    // }
}

template <typename T>

int mywrapper<T>::get(T value)
{
    return 0;//d.at(value);
}

template <typename T>

void mywrapper<T>::pushback(T value)
{
    cout << "pushback " << value << endl;

   // d.push_back(value);
}

template <typename T>

void mywrapper<T>::pushfront(T value)
{
    cout << "pushfront " << value << endl;
   // d.push_front(value);
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

template <typename T>
void mywrapper<T>::addfunction()
{
    d.push_back([]() -> void {
        for (size_t i = 0; i < 100; i++)
        {
            /* code */
            cout << i << endl;
           // cout << "patata" ;
        }
    });
}

void showdq(deque<function_type_m> d)
{

    for (int i = 0; i < d.size(); i++)
    {
        d[i]();
    
        
    }
    cout << '\n'
         << endl;
}

//end .cpp
#endif //MYWRAPPER_H

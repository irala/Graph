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

class mywrapper
{

public:
    mywrapper();
    virtual ~mywrapper();

    static mywrapper &get_pool();
    void get_ioService();
    void addfunction();
    //boost::asio::io_service ioService;
    //boost::asio::io_service::work work;
    //boost::thread_group threadpool;
    //int threads;
    deque<function_type_m> d;

private:
    // using  function_type=void (*myfunction)(int);
};

//start .cpp

mywrapper::mywrapper() //: work(ioService), threads(1)
{
//     for (size_t i = 0; i < threads; i++)
//     {
//         threadpool.create_thread(
//             boost::bind(&boost::asio::io_service::run, &ioService));
//     }
//     cout << "Thread Pool Created" << endl;
 }

mywrapper::~mywrapper()
{
    // ioService.stop();
    // threadpool.join_all();
    // cout << "Thread Pool Terminated" << endl;
}

mywrapper &mywrapper::get_pool()
{
    static mywrapper tp;
    return tp;
}

void methodPool()
{
    cout << "hi " << endl;
}

void mywrapper::get_ioService()
{
    //get_pool().ioService.post(boost::bind(&mywrapper::methodPool));
    // for (size_t i = 0; i < 1000; i++)
    // {
    //     /* code */
    //     cout << i << endl;
    // }
}


void mywrapper::addfunction()
{
    d.push_back([]() -> void {
        for (size_t i = 0; i < 100; i++)
        {
            cout << i << endl;
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

#include <iostream>
#include "graph.h"
#include "taskmanager.h"
#include <map>
#include <memory>
#include <vector>

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

#include "json.hpp"

// for convenience
using json = nlohmann::json;

using std::cin;
using std::cout;

#include <thread>
#include <mutex>

std::mutex mtx;

class test_structure
{

public:
    test_structure()
    {
        cout << "me construyo" << endl;
    }
    virtual ~test_structure()
    {
        cout << "me destruyo" << endl;
    }
};

void test_json()
{
    cout << "EXAMPLE JSON : \n"
         << endl;
    // create object from string literal
    json j = "{ \"happy\": false, \"pi\": 3.141 }"_json;

    std::string s = j.dump();
    std::cout << j.dump(4) << std::endl;

    json j2;
    j2.push_back("foo");
    j2.push_back(1);
    j2.push_back(true);

    // also use emplace_back
    j2.emplace_back(1.78);

    // iterate the array
    for (json::iterator it = j2.begin(); it != j2.end(); ++it)
    {
        std::cout << *it << '\n';
    }
}

void test_boost()
{

    string input("geeks\tfor\tgeeks");
    vector<string> result;
    boost::split(result, input, boost::is_any_of("\t"));

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}

void test_method()
{
    cout << "test_method" << endl;
    //create graph
    graph<string> gr2;

    //create nodes and edges

    gr2.make_node("Madrid");
    gr2.make_node("Barcelona");
    gr2.make_node("Asturias");
    gr2.make_node("Malaga");
    gr2.make_node("Cadiz");
    gr2.make_node("Toledo");
    gr2.make_node("Valencia");
    gr2.make_node("Vigo");
    gr2.make_node("Caceres");

    gr2.add_edge("Madrid", "Toledo", 1);
    gr2.add_edge("Toledo", "Valencia", 2);
    gr2.add_edge("Madrid", "Valencia", 10);

    gr2.add_edge("Valencia", "Barcelona", 2);
    gr2.add_edge("Madrid", "Asturias", 1);
    gr2.add_edge("Toledo", "Cadiz", 1);
    gr2.add_edge("Toledo", "Malaga", 1);
    gr2.add_edge("Malaga", "Cadiz", 1);
    gr2.add_edge("Caceres", "Vigo", 1);
    gr2.add_edge("Malaga", "Vigo", 1);
    gr2.add_edge("Vigo", "Asturia", 1);

    //call find_paths

    auto path = gr2.find_paths("Madrid", "Valencia");
    auto shortest = gr2.get_shortest_path(path);
    auto fastest = gr2.get_fastest_weight(path, "Valencia");

    //el vector que devuelve analizamos con el assert (con la condicion)
    cout << shortest[0]->value << endl;
    assert(shortest[0]->value == ("Madrid"));
}

void print_block(int n, char c)
{
    // critical section (exclusive access to std::cout signaled by locking mtx):
    std::lock_guard<std::mutex> lck(mtx);
    for (int i = 0; i < n; ++i)
    {
        std::cout << c;
    }
    std::cout << '\n';
}

void test_thread()
{
    std::thread th1(print_block, 100, '*');
    std::thread th2(print_block, 100, '$');
    std::thread th3(print_block, 100, '&');
    th1.join();
    th2.join();
    th3.join();
}
bool bye = false;
void infinite_loop_dispatcher(int i)
{

    while (!bye)
    {
        auto resp = taskmanager::get_manager().pop_front();
        if (resp != nullptr)
        {
            std::lock_guard<std::mutex> lck(mtx);
            resp("Your are being dispatched by thread: " + std::to_string(i));
        }
       
    }
}
void something()
{
    cout << "hello thread " << endl;
}

void fill_taskmanager()
{
    //add functions in taskmanager
    taskmanager &t = taskmanager::get_manager();
    cout << "How many task do you want to fill? Insert a number" << endl;
    int number_taskmanager = 10;

    for (size_t i = 0; i < number_taskmanager; i++)
    {
        t.push_back([=](string additional_text){
            cout << additional_text << " " << "Task: "<< i << endl;
        });
    }
}

void send_threads()
{

    fill_taskmanager();

    //create threads
    const auto processor_count = std::thread::hardware_concurrency();
    vector<std::thread *> thread_vector;

    for (size_t i = 0; i < processor_count; i++)
    {
        std::thread *th = new std::thread([i]() {
            infinite_loop_dispatcher(i);
        });
        thread_vector.push_back(th);
    }
    sleep(3);
    bye = true;
    for (size_t i = 0; i < thread_vector.size(); i++)
    {
        thread_vector[i]->join();
        delete thread_vector[i];
    }
}

int main()
{
    //graph<string> gr2; //memoria en stack
    //graph<int>* gr2= new graph<int>();//memoria en heap

    // auto smart_pointer = std::make_shared<test_structure>();

    // test_structure *test = new test_structure();
    // delete test;

    // std::lock_guard<std::mutex> lck(mtx);
    // mywrapper w;
    // w.addfunction();
    // std::thread first(showdq,w.d);
    // std::thread second(showdq,w.d);
    // first.join();
    // second.join();

    send_threads();
    return 0;
}

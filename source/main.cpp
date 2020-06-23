#include <iostream>
#include "graph.h"
#include <map>
#include <memory>
#include <vector>

using std::cin;
using std::cout;

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
  //  auto shortest = gr2.get_shortest_path(path);
    auto fastest = gr2.get_fastest_weight(path, "Valencia");

    //el vector que devuelve analizamos con el assert (con la condicion)
   // cout << shortest[0]->value << endl;
   // assert(shortest[0]->value == ("Madrid"));
}

int main()
{
    graph<string> gr2; //memoria en stack
    //graph<int>* gr2= new graph<int>();//memoria en heap

    auto smart_pointer = std::make_shared<test_structure>();

    test_structure *test = new test_structure();
    delete test;

    test_method();
    return 0;
}

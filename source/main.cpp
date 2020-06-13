#include <iostream>
#include "graph.h"
#include <map>
#include <memory>

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
int main()
{
    graph<string> gr2; //memoria en stack
    //graph<int>* gr2= new graph<int>();//memoria en heap


    auto smart_pointer=std::make_shared<test_structure>();


    test_structure *test = new test_structure();
    delete test;

    gr2.make_node("Madrid");
    gr2.make_node("Barcelona");
    gr2.make_node("Asturias");
    gr2.make_node("Malaga");
    gr2.make_node("Cadiz");
    gr2.make_node("Toledo");
    gr2.make_node("Valencia");
    gr2.make_node("Vigo");
    gr2.make_node("Caceres");

    gr2.add_edge("Madrid", "Toledo", 2);
    gr2.add_edge("Toledo", "Valencia", 3);
    gr2.add_edge("Madrid", "Valencia", 1);

    // gr.add_edge("Valencia", "Barcelona", 2);
    // gr.add_edge("Madrid", "Asturias", 1);
    // gr.add_edge("Toledo", "Cadiz", 1);
    // gr.add_edge("Toledo", "Malaga", 1);
    // gr.add_edge("Malaga", "Cadiz", 1);
    // gr.add_edge("Caceres", "Vigo", 1);
    // gr.add_edge("Madrid", "Valencia", 1);
    // gr.add_edge("Malaga", "Vigo", 1);
    // gr.add_edge("Vigo", "Asturias", 1);

    auto path = gr2.find_paths("Madrid", "Valencia");
    auto shortest = gr2.get_shortest_path(path);
    auto fastest = gr2.get_fastest_weight(path, "Valencia");
    return 0;
}

#include <iostream>
#include "graph.h"
#include <map>

using std::cin;
using std::cout;

int main()
{
    graph<string> gr; //memoria en stack

    //graph<int>* gr2= new graph<int>();//memoria en heap

    gr.make_node("Madrid");
    gr.make_node("Barcelona");
    gr.make_node("Asturias");
    gr.make_node("Malaga");
    gr.make_node("Cadiz");
    gr.make_node("Toledo");
    gr.make_node("Valencia");
    gr.make_node("Vigo");
    gr.make_node("Caceres");

    gr.add_edge("Madrid", "Toledo", 1);
    gr.add_edge("Toledo", "Valencia", 2);
    gr.add_edge("Madrid", "Valencia", 4);

    // gr.add_edge("Valencia", "Barcelona", 2);
    // gr.add_edge("Madrid", "Asturias", 1);
    // gr.add_edge("Toledo", "Cadiz", 1);
    // gr.add_edge("Toledo", "Malaga", 1);
    // gr.add_edge("Malaga", "Cadiz", 1);
    // gr.add_edge("Caceres", "Vigo", 1);
    // gr.add_edge("Madrid", "Valencia", 1);
    // gr.add_edge("Malaga", "Vigo", 1);
    // gr.add_edge("Vigo", "Asturias", 1);

    auto path = gr.find_paths("Madrid", "Valencia");
    // auto path2 = gr.find_shortest_path("Toledo", "Asturias");
    auto result = gr.get_shortest_path(path);
    auto result1=gr.get_fastest_weight(path);
    return 0;
}

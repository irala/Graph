#include <iostream>
#include "graph.h"
#include <map>

using std::cin;
using std::cout;

int main()
{
    graph<string> gr; //memoria en stack

    //graph<int>* gr2= new graph<int>();//memoria en heap

    //int number_nodes;
    //cout << "Please enter a number of nodes do you want to make: ";
    //cin >> number_nodes;
    //for (int i = 1; i <= number_nodes; i++)
    //{
        gr.make_node("Madrid");
        gr.make_node("Barcelona");
        gr.make_node("Asturias");
        gr.make_node("Malaga");
        gr.make_node("Cadiz");
        gr.make_node("Toledo");
        gr.make_node("Valencia");
  //  }
    gr.add_edge("Madrid", "Toledo", 1);
    gr.add_edge("Toledo", "Valencia", 2);
    gr.add_edge("Valencia", "Barcelona", 2);
    gr.add_edge("Madrid", "Asturias", 1);
    gr.add_edge("Toledo", "Cadiz", 1);
    gr.add_edge("Toledo", "Malaga",1);
    gr.add_edge("Malaga", "Cadiz",1);

    auto path = gr.find_shortest_path("Madrid","Valencia");
    for (auto &p : path)
    {
        for (auto &a : p)
        {
            cout << "Node: " << a->value << endl;
        }
    }
    return 0;
}

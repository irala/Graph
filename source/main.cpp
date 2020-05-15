#include <iostream>
#include "graph.h"
#include <map>

using std::cin;
using std::cout;

int main()
{
    graph<int> gr; //memoria en stack

    //graph<int>* gr2= new graph<int>();//memoria en heap

    int number_nodes;
    cout << "Please enter a number of nodes do you want to make: ";
    cin >> number_nodes;
    for (int i = 1; i <= number_nodes; i++)
    {
        gr.make_node(i);
    }

    gr.add_edge(1, 2, 1);
    gr.add_edge(1, 3, 2);
    gr.add_edge(2, 3, 2);
    gr.add_edge(3, 4, 1);
    gr.add_edge(4, 5, 1);
    gr.add_edge(5, 1, 1);

    gr.shortest_way(1, 3);
    return 0;
}
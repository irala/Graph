#include <iostream>
#include "graph.h"

using std::cin;
using std::cout;

int main()
{

    graph gr;
    int number_nodes;
    cout << "Please enter a number of nodes do you want to make";
    cin >> number_nodes;
    for (int i = 1; i <= number_nodes; i++)
    {
        gr.make_node(i);
    }

 
    return 0;
}
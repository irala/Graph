#include "graph.h"
#include <iostream>

using std::cout;
using std::endl;

graph::~graph()
{
    for (auto &element : nodes)
    {
        cout << element.second->value << " destroying node" << endl;
        delete element.second;
    }
}

void graph::make_node(int value)
{
    node* nd = new node(value);
    this->nodes[value]=nd;
    cout << nd->value << " making node" << endl;
}
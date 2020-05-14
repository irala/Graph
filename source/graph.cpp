#include "graph.h"
#include <iostream>
#include <map>

using std::cout;
using std::endl;

// template <typename T>
// graph<T>::~graph()
// {
//     for (auto &element : nodes)
//     {
//         for (auto &e : element.second->edges)
//         {
//             delete e.second;
//             cout << element.second->value << " destroying edge" << endl;
//         }
//         cout << element.second->value << " destroying node" << endl;
//         delete element.second;
//     }
// }

// template <typename T>
// void graph<T>::make_node(T value)
// {
//     node<T> *nd = new node<T>(value);
//     this->nodes[value] = nd;
//     cout << "Node: " << nd->value << " making node" << endl;
// }

// template <typename T>
// bool graph<T>::add_edge(T origin, T destination, T weight)
// {

//     //si en el map existe el nodo origin
//     if (this->nodes.find(origin) != this->nodes.end() && this->nodes.find(destination) != this->nodes.end())
//     {
//         auto &edges = nodes[origin]->edges;
//         if (edges.find(destination) != edges.end())
//         {
//             edges[destination]->weight = weight;
//             cout << "Added egde " << endl;
//             return true;
//         }
//     }
//     else
//     {
//         //si el origin no existe
//         return false;
//     }

//     //aqui hay que crear el edge que no existe
//     edge<T> *e = new edge<T>();
//     e->origin = nodes[origin];
//     e->destination = nodes[destination];
//     e->weight = weight;
//     nodes[origin]->edges[destination] = e;

//     return true;
// }
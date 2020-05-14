#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <map>

using std::cout;
using std::endl;

using std::map;

//forward declarations
template <typename T>
struct node;
template <typename T>
struct edge;

template <typename T>
struct node
{
    T value;

    node(T value) : value(value){};

    map<T, edge<T> *> edges;
};

template <typename T>
struct edge
{
    node<T> *origin;
    node<T> *destination;
    int weight;
};

template <typename T>
class graph
{
public:
    graph() = default;
    virtual ~graph();

    bool add_edge(T origin, T destination, T weight);

    void make_node(T value);

private:
    //the owner of the nodes is graph
    map<T, node<T>*> nodes;
};


template <typename T>
graph<T>::~graph()
{
    for (auto &element : nodes)
    {
        for (auto &e : element.second->edges)
        {
            delete e.second;
            cout << element.second->value << " destroying edge" << endl;
        }
        cout << element.second->value << " destroying node" << endl;
        delete element.second;
    }
}

template <typename T>
void graph<T>::make_node(T value)
{
    node<T> *nd = new node<T>(value);
    this->nodes[value] = nd;
    cout << "Node: " << nd->value << " making node" << endl;
}

template <typename T>
bool graph<T>::add_edge(T origin, T destination, T weight)
{

    //si en el map existe el nodo origin
    if (this->nodes.find(origin) != this->nodes.end() && this->nodes.find(destination) != this->nodes.end())
    {
        auto &edges = nodes[origin]->edges;
        if (edges.find(destination) != edges.end())
        {
            edges[destination]->weight = weight;
            cout << "Added egde " << endl;
            return true;
        }
    }
    else
    {
        //si el origin no existe
        return false;
    }

    //aqui hay que crear el edge que no existe
    edge<T> *e = new edge<T>();
    e->origin = nodes[origin];
    e->destination = nodes[destination];
    e->weight = weight;
    nodes[origin]->edges[destination] = e;

    return true;
}

#endif //GRAPH_H

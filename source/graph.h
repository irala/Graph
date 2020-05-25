#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <map>
#include <vector>
#include <set>

using std::cout;
using std::endl;

using std::map;
using std::set;
using std::string;
using std::vector;

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

    bool add_edge(T origin, T destination, int weight);

    void make_node(T value);

    vector<vector<node<T> *>> find_shortest_path(T origin, T destination);

    void recursive_process(node<T> *current, node<T> *, vector<vector<node<T> *>> &paths, set<node<T> *> &visited);

private:
    //the owner of the nodes is graph
    map<T, node<T> *> nodes;
};

/////////////////////////// .cpp

template <typename T>
graph<T>::~graph()
{
    for (auto &element : nodes)
    {
        for (auto &e : element.second->edges)
        {
            delete e.second;
        }
        delete element.second;
    }
}

//current path with be filled with all the nodes of the find path or will be empty if dont find a path
template <typename T>
void graph<T>::recursive_process(node<T> *current, node<T> *destination, vector<vector<node<T> *>> &paths, set<node<T> *> &visited)
{
    if (current == destination)
    {
        vector<node<T> *> path = new vector<node<T> *>();
        path.push_back(current);
        paths.push_back(path);
        return;
    }
    for (const auto &[k, v] : current->edges)
    {
        if (visited.find(v->destination) != visited.end())
        {
            continue;
        }
        recursive_process(v->destination, destination, paths, visited);
        auto number_of_path=paths.size();
        if (number_of_path )
        {
            paths.push_back(current);
        }
    }
    //add current to visited
    visited.insert(current);
}

//algoritmo para que devuelva la ruta más corta
template <typename T>
vector<vector<node<T> *>> graph<T>::find_shortest_path(T origin, T destination)
{
    //vector de vectores para retornar con los caminos posibles
    vector<vector<node<T> *>> vector_path;
    vector<node<T> *> vector_nodes;
    set<node<T> *> visited;
    cout << "Find the sortest way with : -origin: " << origin << " -destination:" << destination << "\n";
    if (nodes.find(origin) == nodes.end() && nodes.find(destination) == nodes.end())
    {
        cout << "Not exists the nodes in the map" << endl;
        return vector_path;
    }
    recursive_process(nodes[origin], nodes[destination], vector_path, visited);
    for (auto &p : vector_nodes)
    {

        cout << "Node: " << p->value << endl;
    }

    vector_path.push_back(vector_nodes);

    return vector_path;
}

template <typename T>
void graph<T>::make_node(T value)
{
    node<T> *nd = new node<T>(value);
    this->nodes[value] = nd;
}

template <typename T>
bool graph<T>::add_edge(T origin, T destination, int weight)
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

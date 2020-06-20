#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <deque>
#include <memory>
#include <assert.h>

using std::cout;
using std::endl;

using std::deque;
using std::make_shared;
using std::map;
using std::move;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

//forward declarations
template <typename T>
struct node;
template <typename T>
struct edge;

template <typename T>
using node_ptr = shared_ptr<node<T>>;

template <typename T>
using edge_ptr = shared_ptr<edge<T>>;

template <typename T>
struct node
{
    T value;

    node(T value) : value(value){};

    map<T, edge_ptr<T>> edges;
};

template <typename T>
struct edge
{
    node_ptr<T> origin;
    node_ptr<T> destination;
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

    vector<vector<node_ptr<T>>> find_paths(T origin, T destination);

    vector<node_ptr<T>> get_shortest_path(vector<vector<node_ptr<T>>> paths);

    vector<node_ptr<T>> get_fastest_weight(vector<vector<node_ptr<T>>> paths, T destination);

    void recursive_process(node_ptr<T> current, node_ptr<T> destination, vector<vector<node_ptr<T>>> &paths, set<node_ptr<T>> &visited, deque<node_ptr<T>> &uncommited_current_path);


private:
    //the owner of the nodes is graph
    map<T, node_ptr<T>> nodes;
};

/////////////////////////// .cpp

template <typename T>
graph<T>::~graph()
{
}

//current path with be filled with all the nodes of the find path or will be empty if dont find a path
template <typename T>
void graph<T>::recursive_process(node_ptr<T> current, node_ptr<T> destination, vector<vector<node_ptr<T>>> &paths, set<node_ptr<T>> &visited, deque<node_ptr<T>> &uncommited_current_path)
{

    uncommited_current_path.push_back(current);
    //TODO: check infinite recursion if some child nodes contains origin
    if (current == destination)
    {
        vector<node_ptr<T>> st(uncommited_current_path.begin(), uncommited_current_path.end());
        paths.push_back(st);
        uncommited_current_path.pop_back();
        return;
    }

    for (const auto &[k, v] : current->edges)
    {
        if (visited.find(v->destination) != visited.end())
        {
            continue;
        }
        recursive_process(v->destination, destination, paths, visited, uncommited_current_path);
    }
    //add current to visited
    visited.insert(current);
    uncommited_current_path.pop_back();
}

//algoritmo para que devuelva la ruta más corta
template <typename T>
vector<vector<node_ptr<T>>> graph<T>::find_paths(T origin, T destination)
{
    //vector de vectores para retornar con los caminos posibles
    vector<vector<node_ptr<T>>> vector_path;
    set<node_ptr<T>> visited;
    deque<node_ptr<T>> uncommited_current_path;

    cout << "Find the sortest way with : -origin: " << origin << " -destination:" << destination << "\n";
    if (nodes.find(origin) == nodes.end() && nodes.find(destination) == nodes.end())
    {
        cout << "Not exists the nodes in the map" << endl;
        return vector_path;
    }
    recursive_process(nodes[origin], nodes[destination], vector_path, visited, uncommited_current_path);

    return vector_path;
}

template <typename T>
vector<node_ptr<T>> graph<T>::get_shortest_path(vector<vector<node_ptr<T>>> paths)
{
    int shortest = paths.max_size();
    vector<node_ptr<T>> shortest_path;
    for (auto &p : paths)
    {
        if (p.size() < shortest)
        {
            shortest = p.size();
            shortest_path = p;
        }
    }
    cout << "shortest path :" << shortest
         << " size \n"
         << endl;
    for (auto &r : shortest_path)
    {
        cout << "Node: " << r->value << endl;
    }
    return shortest_path;
}

template <typename T>
vector<node_ptr<T>> graph<T>::get_fastest_weight(vector<vector<node_ptr<T>>> paths, T destination)
{
    map<int, vector<node_ptr<T>>> fastests_path;
    for (auto &p : paths)
    {
        int minimun = 0;
        for (size_t i = 0; i < p.size(); ++i)
        {
            int index = i + 1;
            if (index < p.size())
            {
                auto node_aux = p[index]->value;
                minimun = minimun + p[i]->edges[node_aux]->weight;

                if (p[index]->edges.find(destination) != p[index]->edges.end())
                {
                    auto weight_acu = p[index]->edges[destination]->weight;
                    minimun = minimun + weight_acu;
                }
                fastests_path[minimun] = p;
            }
        }
    }

    cout << fastests_path.begin()->first << " Fastest weight" << endl;
    for (auto &f : fastests_path.begin()->second)
    {
        cout << "Node " << f->value << endl;
    }

    return fastests_path.begin()->second;
}

template <typename T>
void graph<T>::make_node(T value)
{
    auto nd = make_shared<node<T>>(value);
    //this->nodes[value] = move(nd);
    this->nodes.emplace(value, nd);
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
    auto e = make_shared<edge<T>>();
    e->origin = nodes[origin];
    e->destination = nodes[destination];
    e->weight = weight;
    nodes[origin]->edges.emplace(destination, e);

    return true;
}


#endif //GRAPH_H



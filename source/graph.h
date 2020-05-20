#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::endl;

using std::map;
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

    bool add_edge(T origin, T destination, T weight);

    void make_node(T value);

    vector<vector<node<T> *>> find_shortest_path(T origin, T destination);

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
            cout << element.second->value << " destroying edge" << endl;
        }
        cout << element.second->value << " destroying node" << endl;
        delete element.second;
    }
}

//algoritmo para que devuelva la ruta más corta
template <typename T>
vector<vector<node<T> *>> graph<T>::find_shortest_path(T origin, T destination)
{
    //vector de vectores para retornar con los caminos posibles
    vector<vector<node<T> *>> vector_path;
    //entero para ir guardando el origin actual
    vector<node<T> *> vector_nodes;
    int current_origin = origin;
    cout << "Find the sortest way with : -origin:" << origin << " -destination:" << destination << "\n";
    if (nodes.find(origin) != nodes.end() && nodes.find(destination) != nodes.end())
    {
        cout << "find origin " << origin << " \n";
        vector_nodes.push_back(nodes[origin]);
        auto &edges = nodes[origin]->edges;
        if (edges.find(destination) != edges.end())
        {
            cout << "find destination to the first time :" << destination << " \n";
            vector_nodes.push_back(nodes[destination]);
        }
        else
        {
            for (auto &e : edges)
            {
                current_origin = e.first;
                if (edges.find(current_origin) != edges.end() && edges.find(destination) != edges.end())
                {
                    vector_nodes.push_back(nodes[current_origin]);
                    if (edges.find(destination) != edges.end())
                    {
                        cout << "find destination " << destination << " \n";
                        vector_nodes.push_back(nodes[destination]);
                    }
                }
            }
        }
        vector_path.push_back(vector_nodes);
    }
    else
    {
        return vector_path;
    }
    //
    //iterar el mapa de nodes para ir recorriendo y mostrar nodes y edges
    // for (auto &element : nodes)
    // {
    //     for (auto &e : element.second->edges)
    //     {

    //         cout << "Edge: "
    //              << "\n";
    //         cout << "Node origen: " << element.second->value << " Node destination:" << e.first << "\n";
    //     }
    // }

    return vector_path;
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

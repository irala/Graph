#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <map>

using std::map;
struct node;
struct edge;
//forward declarations 



struct node
{
    int value;

    node(int value) : value(value){};

    map<int, edge*> edges;
};

struct edge
{
    node *origin;
    node *destination;
    int weight;
};


class graph
{
public:
    graph() = default;
    virtual ~graph();

    bool add_edge(int origin, int destination, int weight);

    void make_node(int value);

private:
    //the owner of the nodes is graph
    map<int, node *> nodes;
};
#endif //GRAPH_H
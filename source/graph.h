#ifndef GRAPH_H
#define GRAPH_H

#include <map>

using std::map;

struct node
{
    int value;

    node(int value) : value(value){};
};

struct edge
{
    int origin, destination, weight;
};

class graph
{
public:
    graph() = default;
    virtual ~graph();

    void make_node(int value);

private:
    //the owner of the nodes is graph
    map<int, node *> nodes;
};
#endif //GRAPH_H
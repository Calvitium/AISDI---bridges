//
// Created by mateusz on 07.01.19.
//

#ifndef MOSTY_GRAPH_H
#define MOSTY_GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
class Graph {
    vector< vector< unsigned> > V_adjacency;
    vector<pair< unsigned , unsigned> > edges;
    unsigned no_vertexes;
    unsigned no_edges;
public:
    Graph() : no_vertexes(0), no_edges(0)
    {}
    explicit Graph(const string &filename);
    bool isBridge(int vertex1, int vertex2);
    void print_graph();
    void get_bridges();
};


#endif //MOSTY_GRAPH_H

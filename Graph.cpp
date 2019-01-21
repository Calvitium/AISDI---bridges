//
// Created by mateusz on 07.01.19.
//

#include <queue>
#include <fstream>
#include "Graph.h"

Graph::Graph(const string &filename) : Graph()
{
    unsigned a, b;
    string path = "/home/mateusz/Pulpit/AISDI/Mosty/" + filename;
    ifstream file(path);
    file>>no_vertexes;
    V_adjacency.resize(no_vertexes);
    while(!file.fail())
    {
        file>>a>>b;
        V_adjacency[a].push_back(b);
        V_adjacency[b].push_back(a);
        edges.push_back({a, b});
        no_edges++;
    }
    no_edges--;
    file.close();
}

bool Graph::isBridge(int vertex1, int vertex2)
{
    if(no_vertexes<=3)
        return false;
    vector<bool> V_visited(no_vertexes);
    queue<unsigned > queue;
    unsigned start = 0;
    unsigned vc = 1;

    for(int i = 1; i<=2; i++)
        if(start == vertex1 || start == vertex2)
            start++;
    for(unsigned i = 0; i < no_vertexes; i++)
        V_visited[i] = false;

    V_visited[vertex1] = true;
    V_visited[vertex2] = true;
    V_visited[start] = true;

    queue.push(start);
    while(!queue.empty())
    {
        unsigned V = queue.front();
        queue.pop();
        for(unsigned neighbour : V_adjacency[V])
        {
            if(V_visited[neighbour]==false)
            {
                V_visited[neighbour] = true;
                queue.push(neighbour);
                vc++;
            }
        }

    }
    if(vc == no_vertexes - 2)
        return false;
    return  true;
}

void Graph::print_graph()
{
    cout<<"No of vertexes: "<<no_vertexes<<endl;
    for(int i = 0; i<no_edges; i++)
        cout<<"Edge: "<<edges[i].first<<" <--> "<<edges[i].second<<endl;
}

void Graph::get_bridges()
{
    cout<<"\n\nBridges: "<<endl;
    for(int i = 0; i<no_edges; i++)
    if(isBridge(edges[i].first, edges[i].second))
        cout<<edges[i].first<<"<-->"<<edges[i].second<<endl;
}



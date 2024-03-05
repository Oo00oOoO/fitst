#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> iPair; // Utility class for weighted edges (destination, weight)

class Graph
{
    int V;                     // Number of vertices
    vector<vector<iPair>> adj; // Adjacency list representation of the graph

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra(int src);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::dijkstra(int src)
{
    // Priority queue to store vertices and their distances
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq; 
    
    // Vector to store distance from the source
    vector<int>dist(V,numeric_limits<int>::max());

    // Insert the source vertex into the priority queue and set its distance to 0
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        // Iterate through all adjacent vertices of u
        for(const auto&neighbor:adj[u]){
            int v=neighbor.first;
            int weight=neighbor.second;

            // If a shorter path is found
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));

            }
        }
    }
    //Print the shortest distance from the source
    cout<<"Shortest distance from source "<<src<<" to each vertex:"<<endl;
    for(int i=0;i<V;++i){
        cout<<"To vertex "<<i<<": "<<dist[i]<<endl;
    }
}
int main()
{
    // Example usage
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 5, 3);

    int source = 0; // Source vertex
    g.dijkstra(source);

    return 0;
}
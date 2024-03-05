#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> iPair; // Utility class for weighted edges (destination, weight)

class Graph
{
    int V;                     // Number of vertices
    vector<vector<iPair>> adj; // Adjacency list representation of the graph

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
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

void Graph::primMST()
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq; // Min-heap to store edges
    int src = 0;

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (const auto &neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    cout << "Edges of MST:" << endl;
    for (int i = 1; i < V; i++)
    {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << endl;
    }
}
int main()
{
    // Example usage
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 7);
    g.primMST();
    return 0;
}
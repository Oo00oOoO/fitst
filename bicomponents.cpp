#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjacencyList;
    vector<int> discoveryTime;
    vector<int> low;
    vector<bool> visited;
    stack<pair<int, int>> edgeStack;
    void dfs(int u, int parent, int &time, vector<vector<int>>
     &biconnectedComponents)
    {
        discoveryTime[u] = low[u] = ++time;
        visited[u] = true;
        for (int v : adjacencyList[u]){
            if (!visited[v]){
                edgeStack.push({u, v});
                dfs(v, u, time, biconnectedComponents);
                low[u] = min(low[u], low[v]);
                if (low[v] > discoveryTime[u]){
                    cout << "Bridge: " << u << " - " << v << endl;
                }
                if (low[v] >= discoveryTime[u]){
                    vector<int> currentComponent;
                    pair<int, int> edge;
                    do{
                        edge = edgeStack.top();
                        edgeStack.pop();
                        currentComponent.push_back(edge.first);
                        currentComponent.push_back(edge.second);
                    } while (edge != make_pair(u, v));
                    cout << "Biconnected Component:";
                    for (int vertex : currentComponent){
                        cout << " " << vertex;
                    }
                    cout << endl;
                    biconnectedComponents.push_back(currentComponent);
                }
            }
            else if (v != parent && discoveryTime[v] < low[u]){
                // update low value to the back edge
                low[u] = discoveryTime[v];
                edgeStack.push({u, v});
            }
        }
    }
public:
    Graph(int V) : vertices(V), adjacencyList(V), 
    discoveryTime(V, -1), low(V, -1), visited(V , false) {}
    void addEdge(int u, int v){
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    void findBiconnectedComponents(){
        int time = 0;
        vector<vector<int>> biconnectedComponents;
        for (int i = 0; i < vertices; ++i)
        {
            if (!visited[i])
            {
                dfs(i, -1, time, biconnectedComponents);
            }
        }
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.findBiconnectedComponents();

    return 0;
}
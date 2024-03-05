#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    void DFS(int startVertex)
    {
        vector<bool> visited(vertices, false);
        stack<int> s;
        cout << "DFS starting from vertex " << startVertex << ": ";
        s.push(startVertex);

        visited[startVertex] = true;
        while (!s.empty())
        {
            int currentVertex = s.top();
            s.pop();
            cout << currentVertex << " ";
            for (int neighbor : adjacencyList[currentVertex])
            {
                if (!visited[neighbor])
                {
                    s.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout<<endl;
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.DFS(0);
    return 0;
}
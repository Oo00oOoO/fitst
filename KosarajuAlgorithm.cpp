#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adj;
    void DFSUtil(int v, vector<bool> &visited, stack<int> &Stack){
        visited[v] = true;
        for (int i : adj[v]){
            if (!visited[i]){
                DFSUtil(i, visited, Stack);
            }
        }
        Stack.push(v);
    }
    void DFSUtilReverse(int v, vector<bool> &visited){
        visited[v] = true;
        cout << v << " ";
        for (int i : adj[v]){
            if (!visited[i]){
                DFSUtilReverse(i, visited);
            }
        }
    }
public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }
    void printStronglyConnectedComponents()
    {
        stack<int> Stack;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i){
            if (!visited[i]){
                DFSUtil(i, visited, Stack);
            }
        }
        // Create a reversedGraph
        Graph reversedGraph(V);
        for (int i = 0; i < V; ++i){
            for (int j : adj[i]){
                reversedGraph.addEdge(j, i);
            }
        }
        // Reset visited array
        fill(visited.begin(), visited.end(), false);
        //by submitting the order of the Stack, we can ensure that the leaders
        // of first time DFS are also the leaders of reversedDFS
        while (!Stack.empty()){
            int v = Stack.top();
            Stack.pop();
            if(!visited[v]){
                reversedGraph.DFSUtilReverse(v,visited);
                cout<<endl;
            }
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(1,3);
    g.addEdge(3,4);

    cout<<"Strongly Connected Components:\n";
    g.printStronglyConnectedComponents();

    return 0;
}

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Graph
{
private:
    int vertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}
    void addEdge(int u, int v)//from u to v
    {
        adjacencyList[u].push_back(v);
    }

    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &stack)
    {
        visited[v] = true;
        for (int neighbor : adjacencyList[v])
        {
            if (!visited[neighbor])
            {
                topologicalSortUtil(neighbor, visited, stack);
            }
        }
        stack.push(v);
    }
    void topologicalSort()
    {
        stack<int> stack;
        vector<bool> visited(vertices, false);
        for (int i = 0; i < vertices; ++i)
        {
            if (!visited[i])
            {
                topologicalSortUtil(i, visited, stack);
            }
        }
        cout << "Topolagical Order: ";
        while (!stack.empty())
        {
            cout << stack.top() << " ";
            stack.pop();
        }
        cout << endl;
    }
};
int main(){
    Graph graph(10);
    graph.addEdge(9,1);
    graph.addEdge(9,5);
    graph.addEdge(9,6);
    graph.addEdge(9,7);
    graph.addEdge(9,8);
    graph.addEdge(8,2);
    graph.addEdge(7,3);
    graph.addEdge(6,3);
    graph.addEdge(1,2);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(5,3);

    cout<<"Graph:\n";
    graph.topologicalSort();
    return 0;
}
// int main() {
// 	Graph g(6);
// 	g.addEdge(5, 2);
// 	g.addEdge(5, 0);
// 	g.addEdge(4, 0);
// 	g.addEdge(4, 1);
// 	g.addEdge(2, 3);
// 	g.addEdge(3, 1);

// 	g.topologicalSort();

// 	return 0;
// }


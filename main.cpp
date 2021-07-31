#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int v;
    list<int>* adj;
    void DFS_Recursive(int v, bool visited[]);
public:
    Graph(int v);
    void Add_Edge(int v, int w);
    void dfs(int v);
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void Graph::Add_Edge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS_Recursive(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " "<<endl;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            DFS_Recursive(*i, visited);
        }
    }
}
void Graph::dfs(int v) {
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    DFS_Recursive(v, visited);
}

int main()
{
    Graph g(4);
    g.Add_Edge(0, 1);
    g.Add_Edge(0, 2);
    g.Add_Edge(1, 2);
    g.Add_Edge(2, 0);
    g.Add_Edge(2, 3);
    g.Add_Edge(3, 3);
    cout << "Depth First Traversal \n\n";
    g.dfs(2);
    return 0;
}

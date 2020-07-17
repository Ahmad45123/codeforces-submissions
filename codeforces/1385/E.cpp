#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // Pointer to an array containing adjacency lists 
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic() 
    // A function used by topologicalSort 
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // to add an edge to graph 
    bool isCyclic();    // returns true if there is a cycle in this graph 
    // prints a Topological Sort of  
// the complete graph 
    vector<int> topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclic() 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
} 

// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil( 
int v, bool visited[],  
                                stack<int> &Stack) 
{ 
    // Mark the current node as visited. 
    visited[v] = true; 
  
    // Recur for all the vertices  
// adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  
    // Push current vertex to stack  
// which stores result 
    Stack.push(v); 
} 
  
// The function to do Topological Sort. 
// It uses recursive topologicalSortUtil() 
vector<int> Graph::topologicalSort() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
// to store Topological 
    // Sort starting from all  
// vertices one by one 
    for (int i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    // Print contents of stack 
    vector<int> ans;
    while (Stack.empty() == false) 
    { 
        ans.push_back(Stack.top()); 
        Stack.pop(); 
    } 
    return ans;
} 

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        Graph g(n+1);
        vector<pair<int, int>> wait;
        vector<pair<int, int>> old;
        for(int i = 0; i < m; i++) {
            int t, x, y; cin >> t >> x >> y;
            if(t == 1) {
                g.addEdge(x, y);
                old.push_back({x, y});
            } else {
                wait.push_back({x, y});
            }
        }

        vector<int> topo = g.topologicalSort();
        vector<int> topoReversed(n+5, 0); // try change default if WA
        for(int i = 0; i < topo.size(); i++) {
            topoReversed[topo[i]] = i;
        }

        vector<pair<int, int>> ans;

        for(int i = 0; i < wait.size(); i++) {
            int x = wait[i].first;
            int y = wait[i].second;
            if(topoReversed[x] < topoReversed[y]) {
                g.addEdge(x, y);
                old.push_back({x, y});
            } else {
                g.addEdge(y, x);
                old.push_back({y, x});
            }
        } 

        if(g.isCyclic()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i].first << " " << ans[i].second << "\n";
            }
            for(int i = 0; i < old.size(); i++) {
                cout << old[i].first << " " << old[i].second << "\n";
            }
        }

    }
    
    return 0;
}
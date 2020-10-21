#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define IsBitSet(x,y) 1==((x >> y)&1) 

class Graph 
{ 
    int V;
    list< pair<int, int> > *adj; 

public: 
    Graph(int V) {
        this->V = V; 
        adj = new list< pair<int, int> >[V]; 
    }
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w)); 
        adj[v].push_back(make_pair(u, w)); 
    }
    int shortest_cycle(int i) 
    { 
        int ans = INT_MAX;  
        vector<int> dist(V, INT_MAX); 
        vector<int> par(V, -1); 

        dist[i] = 0; 
        queue<int> q; 

        q.push(i); 

        while (!q.empty()) { 
            int x = q.front(); 
            q.pop(); 

            for (pair<int, int> child : adj[x]) { 
                if (dist[child.first] == INT_MAX) { 
                    dist[child.first] = child.second + dist[x]; 
                    par[child.first] = x; 
                    q.push(child.first); 

                }  else if (par[x] != child.first and par[child.first] != x) 
                    ans = min(ans, dist[x] + dist[child.first] + child.second); 
            } 
        } 

        return ans; 
    } 
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<ll> arr(n);
    for(ll &x : arr)
        cin >> x;
    
    for(int b = 0; b < 60; b++) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(IsBitSet(arr[i], b)) {
                cnt ++;
            }
        }
        if(cnt >= 3) {
            cout << "3\n";
            return 0;
        }
    }
    
    Graph g(n+1);
    vector<int> toCheck;

    for(int b = 0; b < 60; b++) {
        int x = -1;
        int y = -1;
        for(int i = 0; i < n; i++) {
            if(IsBitSet(arr[i], b)) {
                if(x == -1)
                    x = i+1;
                else if(y == -1)
                    y = i+1;
                else
                    break;
            }
        }
        if(x != -1 && y != -1) {
            g.addEdge(x, y, 1);
            toCheck.push_back(x);
        }
    }

    int ans = INT_MAX;
    for(int x : toCheck) {
        ans = min(ans, g.shortest_cycle(x));
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
    
    return 0;
}
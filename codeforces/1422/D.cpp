#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18


struct point {
    int i;
    int x;
    int y;
    point () {}
    point (int a, int b) : x(a), y(b) {}
};

bool compX(point a, point b) {
    return a.x < b.x;
}
bool compY(point a, point b) {
    return a.y < b.y;
}

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
    vector<ll> shortestPathDijsktra(int src) {
        set< pair<int, int> > setds;
        vector<ll> dist(V, LL_INF);
        
        setds.insert(make_pair(0, src));
        dist[src] = 0;
        
        while (!setds.empty())
        {
            pair<int, int> tmp = *(setds.begin());
            setds.erase(setds.begin());
            
            int u = tmp.second;
            
            list< pair<int, int> >::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            { 
                int v = (*i).first; 
                ll weight = (*i).second; 
                
                if (dist[v] > dist[u] + weight)
                {
                    if (dist[v] != LL_INF)
                        setds.erase(setds.find(make_pair(dist[v], v))); 
                    dist[v] = dist[u] + weight;
                    setds.insert(make_pair(dist[v], v));
                }
            }
        }
        
        return dist; 
    }
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    point s, e;
    cin >> s.x >> s.y >> e.x >> e.y;
    vector<point> tps(m);
    int temp = 3;
    for(point &x : tps) {
        cin >> x.x >> x.y;
        x.i = temp++;
    }

    Graph g(m+5);
    sort(tps.begin(), tps.end(), compX);
    for(int i = 1; i < m; i++) {
        g.addEdge(tps[i].i, tps[i-1].i, min(abs(tps[i].x-tps[i-1].x), abs(tps[i].y-tps[i-1].y)));
    }
    
    sort(tps.begin(), tps.end(), compY);
    for(int i = 1; i < m; i++) {
        g.addEdge(tps[i].i, tps[i-1].i, min(abs(tps[i].x-tps[i-1].x), abs(tps[i].y-tps[i-1].y)));
    }

    for(int i = 0; i < m; i++) {
        g.addEdge(tps[i].i, 1, min(abs(tps[i].x-s.x), abs(tps[i].y-s.y)));
        g.addEdge(tps[i].i, 2, abs(tps[i].x-e.x)+abs(tps[i].y-e.y));
    }
    g.addEdge(1, 2, abs(s.x-e.x)+abs(s.y-e.y));

    vector<ll> dists = g.shortestPathDijsktra(1);
    cout << dists[2] << "\n";

    return 0;
}
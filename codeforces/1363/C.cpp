#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<vector<int>> graph(n+1, vector<int>());
        for(int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n+1);
        queue<pair<int, int>> q;
        q.push({x, 0});
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            vis[cur.first] = true;
            for(int i = 0; i < graph[cur.first].size(); i++) {
                if(!vis[graph[cur.first][i]]) {
                    q.push({graph[cur.first][i], cur.second+1});
                }
            }
        }
        
        cout << (graph[x].size() <= 1 || n % 2 == 0 ? "Ayush" : "Ashish") << "\n";
    }
    
    return 0;
}
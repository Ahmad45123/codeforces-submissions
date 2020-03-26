#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    int in[100001] = {};
    
    vector<pair<int, int>> graph;

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        graph.push_back({u, v});
        in[u] ++;
        in[v] ++;
    }
    int nLeaf = 0;
    for(int i = 1; i <= n; i++)
        if(in[i] == 1)
            nLeaf ++;

    int nCo = 0;
    for(int i = 0; i < n-1; i++) 
    {
        if(in[graph[i].second] == 1 || in[graph[i].first] == 1) {
            cout << nCo ++ << "\n";
        } else {
            cout << nLeaf ++ << "\n";
        }
    }


    return 0;
}
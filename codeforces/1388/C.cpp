#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
bool vis[100001];
bool bad = false;
vector<int> citizens;
vector<int> happy;
vector<int> good;
vector<vector<int>> graph;

int countEntries(int i) {
    if(vis[i])
        return 0;
    vis[i] = true;    

    int cnt = 0;
    for(int j = 0; j < graph[i].size(); j++) {
        cnt += countEntries(graph[i][j]);
    }

    int total = cnt+citizens[i];
    if((total+happy[i]) % 2 != 0) {
        bad = true;
    }
    good[i] = (total+happy[i])/2;
    if(good[i] > total) {
        bad = true;
    }

    int totalChildGood = 0;
    for(int j = 0; j < graph[i].size(); j++) {
        totalChildGood += good[graph[i][j]];
    }
    if(good[i] < totalChildGood) {
        bad = true;
    }

    return total;
} 

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        citizens = vector<int>(n+1);
        happy = vector<int>(n+1);
        good = vector<int>(n+1);
        graph = vector<vector<int>>(n+1, vector<int>());
        bad = false;
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; i++) {
            cin >> citizens[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> happy[i];
        }
        for(int i = 0; i < n-1; i++) {
            int x, y; cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        countEntries(1);
        
        if(bad) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    
    return 0;
}
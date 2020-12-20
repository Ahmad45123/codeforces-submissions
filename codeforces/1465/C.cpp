#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isCyclic(int x, vector<int> &tmp, vector<int> &vis) {
    if(x == -1)
        return false;
    if(vis[x] == 2)
        return true;
    else if(vis[x])
        return false;
    vis[x] = true;
    return isCyclic(tmp[x], tmp, vis);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> arr(m);
        for(auto &x : arr)
            cin >> x.first >> x.second;

        vector<int> tmp(n+1, -1);
        for(auto x : arr)
            tmp[x.first] = x.second;

        int numLocked = 0;
        int ans = 0;
        for(int i = 0; i < m; i++) {
            if(arr[i].first == arr[i].second) continue;
            ans ++;
        }

        vector<int> vis(n+1, 0);
        for(int i = 0; i < m; i++) {
            if(arr[i].first == arr[i].second) { 
                vis[arr[i].first] = true;
                continue;
            }
            if(vis[arr[i].first]) continue;
            vis[arr[i].first] = 2;
            if(isCyclic(tmp[arr[i].first], tmp, vis))
                ans ++;
            vis[arr[i].first] = 1;
        }

        cout << ans << "\n";
    }
    
    return 0;
}
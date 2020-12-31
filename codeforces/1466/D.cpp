#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> weights(n+1);
        vector<int> graph(n+1);
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> weights[i];
            ans += weights[i];
        }
        for(int i = 0; i < n-1; i ++) {
            int u, v; cin >> u >> v;
            graph[u] ++;
            graph[v] ++;
        }

        vector<pair<int, int>> q;
        for(int i = 1; i <= n; i++) {
            if(graph[i] > 1) {
                q.push_back({weights[i], graph[i]-1});
            }
        }

        sort(q.begin(), q.end());

        cout << ans << " ";
        for(int i = 0; i < n-2; i++) {
            auto tp = q.end(); tp --;
            ans += tp->first;
            tp->second --;
            if(tp->second == 0)
                q.pop_back();
            cout << ans << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
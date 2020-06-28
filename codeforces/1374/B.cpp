#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        queue<pair<ll, int>> q;
        q.push({1, 0});
        set<ll> vis;
        bool found = false;
        int ans = 1e9;
        while(!q.empty()) {
            auto front  = q.front();
            q.pop();
            if(vis.find(front.first) != vis.end())
                continue;
            vis.insert(front.first);
            if(front.first == n) {
                found = true;
                ans = min(ans, front.second);
                continue;
            } else if(front.first > n*2) {
                continue;
            } else {
                if(front.first % 2 == 0)
                    q.push({front.first/2, front.second+1});
                q.push({front.first*6, front.second+1});
            }
        }
        cout << (found ? ans : -1) << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q; cin >> q;
    while(q--) {
        int b, w; cin >> b >> w;
        set<pair<int, int>> whites;
        set<pair<int, int>> blacks;
        map<pair<int, int>, bool> vis;
        vector<pair<int, int>> ans;
        whites.insert({1e9/2, 1e9/2});
        while(b > 0 || w > 0) {
            if((whites.size() == 0 && w > 0 && b == 0) || (blacks.size() == 0 && b > 0 && w == 0)) {
                ans.clear();
                break;
            }
            if(w > 0 && whites.size() > 0) {
                auto cur = whites.begin();
                ans.push_back(*cur);
                vis[*cur] = true;
                if(cur->first+1 <= 1e9 && !vis[{cur->first+1, cur->second}])
                    blacks.insert({cur->first+1, cur->second});
                if(cur->second+1 <= 1e9 && !vis[{cur->first, cur->second+1}])
                    blacks.insert({cur->first, cur->second+1});
                if(cur->first-1 >= 1 && !vis[{cur->first-1, cur->second}])
                    blacks.insert({cur->first-1, cur->second});
                if(cur->second-1 >= 1 && !vis[{cur->first, cur->second-1}])
                    blacks.insert({cur->first, cur->second-1});
                whites.erase(cur);
                w --;
            }
            if(b > 0 && blacks.size() > 0) {
                auto cur = blacks.begin();
                ans.push_back(*cur);
                vis[*cur] = true;
                if(cur->first+1 <= 1e9 && !vis[{cur->first+1, cur->second}])
                    whites.insert({cur->first+1, cur->second});
                if(cur->second+1 <= 1e9 && !vis[{cur->first, cur->second+1}])
                    whites.insert({cur->first, cur->second+1});
                if(cur->first-1 >= 1 && !vis[{cur->first-1, cur->second}])
                    whites.insert({cur->first-1, cur->second});
                if(cur->second-1 >= 1 && !vis[{cur->first, cur->second-1}])
                    whites.insert({cur->first, cur->second-1});
                blacks.erase(cur);
                b --;
            }
        }

        if(ans.size()) {
            cout << "YES\n";
            for(auto &x : ans) {
                cout << x.first << " " << x.second << "\n";
            }
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
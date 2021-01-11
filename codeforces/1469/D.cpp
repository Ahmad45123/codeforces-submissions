#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int, int>> ans;
        if(n <= 8) {
            for(int i = 3; i <= n-1; i++) {
                ans.push_back({i, i+1});
            }
            int tmp = n;
            while(tmp != 1) {
                ans.push_back({n, 2});
                tmp = ceil(tmp*1.0/2.0);
            }
        } else {
            for(int i = 9; i <= n-1; i++) { // ALL elements from 9 to n-1 are now one
                ans.push_back({i, i+1});
            }
            int tmp = n;
            while(tmp != 1) {
                ans.push_back({n, 8});
                tmp = ceil(tmp*1.0/8.0);
            }
            for(int i = 3; i < 8; i ++) {
                ans.push_back({i, i+1});
            }
            ans.push_back({8, 2});
            ans.push_back({8, 2});
            ans.push_back({8, 2});
        }
        cout << ans.size() << "\n";
        for(auto x : ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    
    return 0;
}
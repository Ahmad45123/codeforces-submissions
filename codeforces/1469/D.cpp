#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int x, vector<pair<int, int>> &ans) {
    if(x <= 2) return;

    int y = 1;
    while(y < ceil(x*1.0/y))
        y ++;

    for(int i = y+1; i < x; i++)
        ans.push_back({i, x});
    ans.push_back({x, y});
    ans.push_back({x, y});

    solve(y, ans);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int, int>> ans;
        solve(n, ans);    
        cout << ans.size() << "\n";
        for(auto x : ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    
    return 0;
}
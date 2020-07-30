#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;

    vector<pair<int, int>> ans;
    int i = 0, j = 0;
    ans.push_back({i, j-1});
    ans.push_back({i-1, j});
    for(int t = 0; t < n; t++) {
        ans.push_back({i, j});
        ans.push_back({i, j+1});
        ans.push_back({i+1, j});
        i += 1, j += 1;
    }

    ans.push_back({-1, -1});
    ans.push_back({i, j});

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";

    return 0;
}
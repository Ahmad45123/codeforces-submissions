#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<pair<int, int>> list(m);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        list[i] = {a, b};
    }
    sort(list.begin(), list.end(), compare);
    //reverse(list.begin(), list.end());
    
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < m; i++) {
        int amnt = min(cur+list[i].first, n);
        ans += list[i].second*(amnt-cur);
        cur += (amnt-cur);
    }

    cout << ans << "\n";

    return 0;
}
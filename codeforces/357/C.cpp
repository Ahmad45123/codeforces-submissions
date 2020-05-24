#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    set<int> arr;
    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++)
        arr.insert(i);
    
    for(int i = 0; i < m; i++) {
        int l, r, x; cin >> l >> r >> x;
        auto from = arr.lower_bound(l);
        auto to = arr.upper_bound(r);
        for(auto it = from; it != to; it++)
            if(*it != x) ans[*it] = x;
        arr.erase(from, to);
        arr.insert(x);
    }
    
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " "; 
    }
    cout << '\n';

    return 0;
}
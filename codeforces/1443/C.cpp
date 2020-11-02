#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<ll, ll>> arr(n);
        for(auto &x : arr)
            cin >> x.first;
        
        for(auto &x : arr)
            cin >> x.second;
        
        sort(arr.begin(), arr.end(), comp);

        vector<ll> sum(n+1, 0);
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i-1] + arr[i-1].second;
        }

        ll ans = min(arr[0].first, sum[n]);
        for(int i = 0; i < n; i++)
            ans = min(ans, max(arr[i].first, sum[i]));

        cout << ans << "\n";
    }
    
    return 0;
}
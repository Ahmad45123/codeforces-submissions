#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<pair<ll, ll>> arr(n);
        for(auto &x : arr)
            cin >> x.first, x.second = 1;

        for(int i = 0;; i ++) {
            if(arr[i].first % x != 0)
                break;
            arr.push_back({arr[i].first / x, x*arr[i].second});
        }

        ll sum = 0;
        for(auto x : arr)
            sum += x.first * x.second;
        
        cout << sum << "\n";
    }
    
    return 0;
}
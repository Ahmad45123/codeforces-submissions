#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<ll> arr(n);
    vector<ll> intervals(m);
    for(auto &x : arr)
        cin >> x;
    for(auto &x : intervals)
        cin >> x;
    
    ll gcd = arr[1]-arr[0];
    for(int i = 1; i < n; i++) {
        gcd = __gcd(gcd, arr[i]-arr[i-1]);
    }
    int ans = -1;
    for(int i = 0; i < m; i++) {
        if(gcd % intervals[i] == 0) {
            ans = i+1;
            break;
        }
    }
    
    if(ans != -1) {
        cout << "YES\n" << arr[0] << " " << ans << "\n";
    } else 
        cout << "NO\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<ll> arr(n);
    vector<ll> b(m);
    for(auto &x : arr)
        cin >> x;
    for(auto &y : b) {
        cin >> y;
    }

    ll semiAns = 0;
    for(int i = 1; i < n; i++) {
        semiAns = __gcd(semiAns, abs(arr[i]-arr[i-1]));
    }

    for(int i = 0; i < m; i++) {
        cout << __gcd(arr[0]+b[i], semiAns) << " ";
    }
    
    return 0;
}
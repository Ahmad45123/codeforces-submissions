#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<ll> arr(n+3);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    for(int i = 1; i <= n; i++) {
        arr[i] += arr[i-1];
    }

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << (arr[r]-arr[l-1])/10 << "\n";
    }
    
    return 0;
}
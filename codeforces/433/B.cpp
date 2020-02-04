#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<ll> arr(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<ll> sorted = arr;
    sort(sorted.begin(), sorted.end());

    for(int i = 1; i <= n; i++) {
        arr[i] += arr[i-1];
        sorted[i] += sorted[i-1];
    }

    int m; cin >> m;
    while(m--) {
        int type, l, r; cin >> type >> l >> r;
        if(type == 1) {
            cout << arr[r]-arr[l-1] << "\n";
        } else {
            cout << sorted[r]-sorted[l-1] << "\n";
        }
    }
    
    return 0;
}
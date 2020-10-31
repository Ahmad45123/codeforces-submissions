#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<ll> arr(n);
        for(ll &x : arr)
            cin >> x;
        
        sort(arr.begin(), arr.end(), greater<ll>());
        for(int i = 1; i < min(k+1, n); i++) {
            arr[0] += arr[i];
        }

        cout << arr[0] << "\n";
    }
    
    return 0;
}
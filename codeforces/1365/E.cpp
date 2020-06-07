#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    if(n <= 3)
        for(auto x : arr)
            ans |= x;
    else {
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    ans = max(ans, arr[i] | arr[j] | arr[k]);
                }
            }
        }   
    }

    cout << ans << "\n";
    
    return 0;
}
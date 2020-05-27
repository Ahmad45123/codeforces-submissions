#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll n; cin >> n;
    int m; cin >> m;
    ll k; cin >> k;
    vector<ll> arr(m);
    for(int i = 0; i < m; i++) {
        ll x; cin >> x;
        arr[i] = x-1;
    }

    sort(arr.begin(), arr.end());

    int temp = 1;
    int removed = 0;
    int steps = 0;
    for(int i = 1; i < m; i++) {
        ll me = arr[i]-removed;
        ll prev = arr[i-1]-removed;
        if(me-prev+1 <= k && me%k > prev%k) {
            temp ++;
        } else {
            steps += 1;
            removed += temp;
            temp = 1;
        }
    }
    if(temp > 0)
        steps += 1;
    
    cout << steps << "\n";

    return 0;
}
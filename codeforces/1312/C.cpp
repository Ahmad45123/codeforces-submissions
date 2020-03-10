#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
map<ll, bool> used;

bool isPossible(ll v) {
    int index = 0;
    while(v != 0) {
        ll mod = v%k;
        if(mod == 1) {
            if(used[index])
                return false;
            used[index] = true;
        } else if(mod != 0) {
            return false;
        }
        v /= k;
        index ++;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll t; cin >> t;
    while(t--) {
        cin >> n >> k;
        used = map<ll, bool>();
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++)
            cin >> arr[i];

        bool good = true;
        for(ll i = 0; i < n; i++) {
            if(!isPossible(arr[i])) {
                good = false;
                break;
            }
        }

        if(good) 
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
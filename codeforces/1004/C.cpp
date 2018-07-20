#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    ll n; cin >> n;
    vector<ll> arr(n);
    vector<ll> right(n);
    for(ll i = 0; i < n; i++)
        cin >> arr[i];
    
    map<ll, bool> passed;
    ll temp = 0;
    for(ll i = n-1; i >= 1; i--) {
        if(!passed[arr[i]]) {
            temp++;
            passed[arr[i]] = true;
        }
        right[i] = temp;
        /*else {
            break;
        }*/
    }

    passed.clear();

    ll ans = 0;
    for(ll i = 0; i < n-1; i++) {
        if(!passed[arr[i]]) {
            passed[arr[i]] = true;
            ans += right[i+1];
        }
    }

    cout << ans;
    return 0;
}
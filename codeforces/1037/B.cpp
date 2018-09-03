#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, s; cin >> n >> s;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    ll mid = n/2.0f;

    ll ans = 0;
    for(int i = mid; i < n; i++) {
        if(s > arr[i])
            ans += s-arr[i]; 
    }

    ll ans2 = 0;
    for(int i = 0; i <= mid; i++) {
        if(s < arr[i])
            ans2 += arr[i]-s; 
    }

    if(ans == 0)
        cout << ans2;
    else if(ans2 == 0)
        cout << ans;
    else 
        cout << min(ans, ans2);
    return 0;
}
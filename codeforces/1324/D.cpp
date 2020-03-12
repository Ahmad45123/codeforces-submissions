#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    for(int i = 0; i < n; i++)
        cin >> arr2[i];
    
    vector<int> subs1(n);
    vector<int> subs2(n);

    for(int i = 0; i < n; i++) {
        subs1[i] = arr1[i]-arr2[i];
        subs2[i] = arr2[i]-arr1[i];
    }

    sort(subs1.begin(), subs1.end());
    sort(subs2.begin(), subs2.end());

    ll ans = 0;

    for(int x : subs1) {
        auto v = lower_bound(subs2.begin(), subs2.end(), x);
        int ind = (v-subs2.begin());
        //if(ind >= n) continue;
        ans += ind;
    }

    for(int i = 0; i < n; i++)
        if(arr1[i]*2 > arr2[i]*2)
            ans --;

    cout << ans/2 << "\n";

    return 0;
}
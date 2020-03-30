#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    map<int, ll> ans;
    for(int i = 0; i < n; i++) {
        ans[i+1-arr[i]] += arr[i];
    }

    ll tmp = 0;
    for(auto x : ans)
        tmp = max(tmp, x.second);

    cout << tmp << "\n";

    return 0;
}
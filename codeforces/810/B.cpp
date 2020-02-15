#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, f;

bool comp(pair<int, int> a, pair<int, int> b) {
    return min(a.second, a.first*2)-min(a.second, a.first) > min(b.second, b.first*2)-min(b.second, b.first);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> f;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++) {
        int k, l; cin >> k >> l;
        arr[i] = {k, l};
    }

    sort(arr.begin(), arr.end(), comp);
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(i < f)
            ans += min(arr[i].first*2, arr[i].second);
        else
            ans += min(arr[i].first, arr[i].second);
    }

    cout << ans << "\n";
    return 0;
}
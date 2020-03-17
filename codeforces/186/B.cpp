#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

bool comp(pair<int, double> a, pair<int, double> b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, t1, t2, k; cin >> n >> t1 >> t2 >> k;
    vector<pair<int, int>> arr(n);
    for(auto &i : arr)
        cin >> i.first >> i.second;
    
    vector<pair<int, double>> ans;
    for(int i = 0; i < n; i++) {
        double mn = min(arr[i].first, arr[i].second);
        double mx = max(arr[i].first, arr[i].second);
        ans.push_back({i+1, max(mn*t1-mn*t1*k/100.0+mx*t2, mx*t1-mx*t1*k/100.0+mn*t2)});
    }
    
    sort(ans.begin(), ans.end(), comp);

    for(auto i : ans) {
        cout << i.first << " " << fixed << setprecision(2) << i.second << "\n";
    }

    return 0;
}
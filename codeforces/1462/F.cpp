#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int, int>> arr(n);
        vector<int> begins;
        vector<int> ends;
        for(int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
            begins.push_back(arr[i].first);
            ends.push_back(arr[i].second);
        }
        sort(begins.begin(), begins.end());
        sort(ends.begin(), ends.end());
        int ans = n;
        for(int i = 0; i < n; i++) {
            int it = lower_bound(ends.begin(), ends.end(), arr[i].first)-ends.begin();
            int tmp = begins.end() - upper_bound(begins.begin(), begins.end(), arr[i].second);
            ans = min(ans, it+tmp);
        }
        cout << ans << "\n";
    }
    
    return 0;
}
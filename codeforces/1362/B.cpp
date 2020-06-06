#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int xr = arr[i]^arr[j];
                mp[xr] ++;
            }
        }
        int ans = -1;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second == n) {
                ans = it->first;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
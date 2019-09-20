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
        for(int i = 0; i < n; i++) {
            int val; cin >> val;
            arr[i] = make_pair(val, i+1);
        }

        sort(arr.begin(), arr.end());

        int ans = 0;
        int mx = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i].second > mx)
                mx = arr[i].second;
            else {
                ans ++;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
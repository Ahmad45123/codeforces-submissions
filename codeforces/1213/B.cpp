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
        for(int i = 0; i < n; i++) {
            int val; cin >> val;
            arr[i] = val;
        }
        int ans = 0;
        int mx = INT_MAX;
        for(int i = n-1; i >= 0; i--) {
            if(arr[i] > mx)
                ans++;
            mx = min(arr[i], mx);
        }

        cout << ans << "\n";
    }
    
    return 0;
}
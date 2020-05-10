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
        for(auto &x : arr)
            cin >> x;
        
        sort(arr.begin(), arr.end());

        if(arr.size() == 1)
            cout << 1 << "\n";
        else {
            int ans = 1;
            for(int i = 1; i < n; i++) {
                if(arr[i] - arr[i-1] == 1) {
                    ans = 2;
                    break;
                }
            }
            cout << ans << "\n";
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<int> arr(n);
        for(auto &x : arr)
            cin >> x;
        
        int ans = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum % x != 0)
                ans = max(ans, i+1);
        }

        sum = 0;
        for(int i = n-1; i >= 0; i--) {
            sum += arr[i];
            if(sum % x != 0)
                ans = max(ans, n-i);
        }


        cout << (ans == 0 ? -1 : ans) << "\n";
    }
    
    return 0;
}
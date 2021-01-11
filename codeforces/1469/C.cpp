#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        
        bool good = true;
        int l = arr[0], r = arr[0];
        for(int i = 1; i < n; i++) {
            l = max(arr[i], l-k+1);
            r = min(arr[i]+k-1, r+k-1);
            if(r-l+1 <= 0) good = false;
        }

        cout << (good && arr[n-1] >= l && arr[n-1] <= r ? "YES\n" : "NO\n");
    }
    
    return 0;
}
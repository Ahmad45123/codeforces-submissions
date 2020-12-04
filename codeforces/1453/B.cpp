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
        
        int mxDiff = 0;
        int mnIdx = -1;

        for(int i = 1; i < n-1; i++) {
            if(abs(arr[i]-arr[i-1]) + abs(arr[i]-arr[i+1]) > abs(arr[i+1]-arr[i-1])) {
                int diff = abs(arr[i]-arr[i-1]) + abs(arr[i]-arr[i+1]) - abs(arr[i+1]-arr[i-1]);
                if(diff > mxDiff) {
                    mxDiff = diff;
                    mnIdx = i;
                }
            }
        }

        if(abs(arr[0]-arr[1]) > mxDiff) {
            mnIdx = 0;
            mxDiff = abs(arr[0]-arr[1]);
        }
        
        if(abs(arr[n-1]-arr[n-2]) > mxDiff) {
            mnIdx = n-1;
            mxDiff = abs(arr[n-1]-arr[n-2]);
        }

        if(mnIdx != -1) {
            if(mnIdx != 0)
                arr[mnIdx] = arr[mnIdx-1];
            else
                arr[mnIdx] = arr[mnIdx+1];
        }
        
        ll ans = 0;
        for(int i = 1; i < n; i++)
            ans += abs(arr[i]-arr[i-1]);
        cout << ans << "\n";
    }
    
    return 0;
}
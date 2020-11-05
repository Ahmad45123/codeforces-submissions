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
        
        bool good = true;
        
        vector<int> increasing(n);
        vector<int> decreasing(n);
        decreasing[0] = arr[0];
        for(int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i-1];
            if(diff > 0) {
                increasing[i] = increasing[i-1] + diff;
                decreasing[i] = decreasing[i-1];
            } else {
                increasing[i] = increasing[i-1];
                decreasing[i] = decreasing[i-1] + diff;
            }
            if(decreasing[i] < 0) {
                good = false;
                break;
            }
        }

        cout << (good ? "YES\n" : "NO\n");
    }
    
    return 0;
}
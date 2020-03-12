#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        int mx = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            mx = max(arr[i], mx);
        }
        
        bool good = true;

        for(int x : arr) {
            if((mx-x) % 2 != 0) {
                good = false;
                break;
            }
        }

        if(good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
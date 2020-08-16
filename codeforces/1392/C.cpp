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
        
        if(n == 1) {
            cout << "0\n";
            continue;
        }

        ll ans = 0;

        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[i-1]) {
                int j = i+1;
                int mnElem = arr[i];
                int mxElem = arr[i];
                while(arr[j] >= arr[j-1] && j < n) {
                    mnElem = min(mnElem, arr[j]);
                    mxElem = max(mxElem, arr[j]);
                    j ++;
                }
                ans += (mxElem-mnElem)+(arr[i-1]-mxElem);
                i = j-1;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
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
        
        ll ans = 0;
        
        int i = 1;
        int storage = 1;
        while(i < n) {
            ans ++;
            int tmpCnt = 0;
            while(storage > 0 && i < n) {
                i++;
                tmpCnt ++;
                for(; i < n; i++) {
                    if(arr[i] < arr[i-1]) break;
                    tmpCnt ++;
                }
                storage --;
            }
            storage = tmpCnt;
        }

        cout << ans << "\n";
    }
    
    return 0;
}
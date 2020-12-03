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
        for(int &i : arr)
            cin >> i;
        
        int ans = 0;
        while(true) {
            bool sorted = true;
            for(int i = 1; i < n; i++)
                if(arr[i] < arr[i-1]) {
                    sorted = false;
                }
            if(sorted)
                break;

            int pos = -1;
            for(int i = 0; i < n; i++) {
                if(arr[i] > x) {
                    pos = i;
                    break;
                }
            }
            
            if(pos == -1) {
                ans = -1;
                break;
            } else {
                swap(arr[pos], x);
                ans ++;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q; cin >> q;
    while(q--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        
        int oddCount = 0;
        for(int x : arr)
            if(x % 2 != 0)
                oddCount ++;
        
        if(oddCount >= k && oddCount % 2 == k % 2) {
            cout << "YES\n";
            for(int i = 0, p = 0; i < n && p < k-1; i++) {
                if(arr[i] % 2 != 0) {
                    cout << i+1 << " ";
                    p ++;
                }
            }
            cout << n << "\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
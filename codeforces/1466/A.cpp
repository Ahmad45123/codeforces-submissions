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
        vector<bool> passed(51);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int diff = abs(arr[i]-arr[j]);
                if(!passed[diff]) {
                    passed[diff] = true;
                    ans ++;
                }
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}
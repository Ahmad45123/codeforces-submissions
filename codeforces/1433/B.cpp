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
        
        int s = 0;
        int e = n-1;
        while(arr[e] != 1 && e >= 0)
            e --;
        while(arr[s] != 1 && s < n)
            s ++;

        int ans = 0;
        int prevOne = s;
        for(int i = s+1; i <= e; i++) {
            if(arr[i] == 1) {
                ans += i-prevOne-1;
                prevOne = i;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
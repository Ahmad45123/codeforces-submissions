#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(100001);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            arr[x] ++;
        }
        
        sort(arr.begin(), arr.end(), greater<int>());

        int toDiv = arr[0]-1;
        ll sum = 0;
        for(int i = 1; i <= 100000; i++) {
            sum += min(arr[i], toDiv);
        }
        
        ll ans = sum/toDiv;
        cout << ans << "\n";
    }
    
    return 0;
}
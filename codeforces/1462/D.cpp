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
        int mx = *max_element(arr.begin(), arr.end());
        ll sum = 0;
        for(int &x : arr)
            sum += x;
        for(int ans = n; ans >= 1; ans --) {
            if(sum % ans == 0) {
                int perEl = sum/ans;
                bool good = true;
                ll curSum = 0;
                for(int i = 0; i < n; i++) {
                    curSum += arr[i];
                    if(curSum == perEl)
                        curSum = 0;
                    else if(curSum > perEl) {
                        good = false;
                        break;
                    }
                }
                if(good) {
                    cout << n-ans << "\n";
                    break;
                }
            }
        }
    }
    
    return 0;
}
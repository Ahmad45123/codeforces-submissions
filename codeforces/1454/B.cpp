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
        map<int, int> passedCnt;
        int ansValue = 1e9;
        for(int &x : arr) {
            cin >> x;
            passedCnt[x] ++;
        }
        
        for(auto it = passedCnt.begin(); it != passedCnt.end(); it ++) {
            if(it->second == 1) {
                ansValue = min(ansValue, it->first);
            }
        }

        int ans = -1;
        for(int i = 0; i < n; i++)
            if(arr[i] == ansValue) {
                ans = i+1;
                break;
            }

        cout << ans << "\n";
    }
    
    return 0;
}
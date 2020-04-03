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
        for(auto &x : arr)
            cin >> x;

        bool vis[200001] = {};
        ll curSum = 0;
        vector<int> left;

        for(ll i = 0; i < n; i++) {
            if(vis[arr[i]]) {
                break;
            }

            vis[arr[i]] = true;
            curSum += arr[i];
            if(curSum == ((i+1LL)*(i+2LL)/2LL)) {
                left.push_back(i+1);
            }
        }

        memset(vis, 0, sizeof vis);
        curSum = 0;
        ll counter = 1;
        vector<pair<int, int>> ans;

        sort(left.begin(), left.end());
        for(int i = n-1; i >= 0; i--) {
            if(vis[arr[i]]) {
                break;
            }

            vis[arr[i]] = true;
            curSum += arr[i];
            if(curSum == ((counter)*(counter+1LL)/2LL)) {
                if(n-counter > 0 && binary_search(left.begin(), left.end(), n-counter)) {
                    ans.push_back({n-counter, counter});
                }
            }
            counter ++;
        }

        cout << ans.size() << "\n";
        for(auto x : ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    
    return 0;
}
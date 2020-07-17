#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(2*n);
        for(int &x : arr)
            cin >> x;
        
        map<int, bool> vis;
        vector<int> ans;

        for(int i = 0; i < 2*n; i++) {
            if(!vis[arr[i]]) {
                vis[arr[i]] = true;
                ans.push_back(arr[i]);
            }
        }

        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
    
    return 0;
}
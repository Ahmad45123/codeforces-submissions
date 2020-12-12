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
        vector<int> pos(n+1);
        for(int i = 0; i < n; i++)
            pos[arr[i]] = i;
        
        vector<bool> ans(n+1);
        int l = pos[1], r = pos[1];
        for(int i = 1; i <= n; i++) {
            l = min(l, pos[i]);
            r = max(r, pos[i]);
            if(r-l+1 == i)
                ans[i] = true;
        }

        for(int i = 1; i <= n; i++)
            cout << ans[i];
        cout << "\n";
    }
    
    return 0;
}
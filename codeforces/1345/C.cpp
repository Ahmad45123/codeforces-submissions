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
        
        map<int, bool> vis;
        bool good = true;

        for(int i = 0; i < n; i++) {
            int tmp = (arr[i]+i)%n;
            if(tmp < 0) tmp += n;
            if(vis[tmp])
                good = false;
            vis[tmp] = true;
        }

        for(int i = 0; i < n; i++)
            if(!vis[i])
                good = false;

        cout << (good ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
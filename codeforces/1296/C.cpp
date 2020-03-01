#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char getComplement(char t) {
    switch (t)
    {
        case 'U':
            return 'D';
        case 'D':
            return 'U';
        case 'L':
            return 'R';
        case 'R': 
            return 'L';
    }
}

int main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        map<pair<int, int>, int> vis;
        vis[{0, 0}] = 0;
        int x = 0, y = 0;
        int l = -1, r = 1e9;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'R') x ++;
            else if(s[i] == 'L') x --;
            else if(s[i] == 'U') y ++;
            else y--;

            if(vis.count({x, y})) {
                if(i-vis[{x, y}] < r-l) {
                    l = vis[{x, y}];
                    r = i;
                }
            }

            vis[{x, y}] = i+1;
        }

        if(l == -1)
            cout << -1 << "\n";
        else
            cout << l+1 << " " << r+1 << "\n";
    }
    
    return 0;
}
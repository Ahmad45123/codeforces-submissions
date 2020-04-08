#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> from(n);
        vector<int> to(n);
        for(auto &x : from)
            cin >> x;
        for(auto &x : to)
            cin >> x;
        
        bool passplus = false;
        bool passminus = false;

        bool bad = false;

        for(int i = 0; i < n; i++) {
            if(i > 0) {
                if(from[i-1] == 1)
                    passplus = true;
                else if(from[i-1] == -1)
                    passminus = true;
            }

            if(to[i] == from[i])
                continue;
            if(from[i] > to[i] && !passminus) {
                bad = true;
                break;
            }
            if(from[i] < to[i] && !passplus) {
                bad = true;
                break;
            }
        }

        if(bad)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    
    return 0;
}
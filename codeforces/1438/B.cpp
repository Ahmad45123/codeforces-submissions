#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        map<int, bool> added;
        bool good = true;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(added[x]) {
                good = false;
            }
            added[x] = true;
        }

        cout << (good ? "NO\n" : "YES\n");
    }
    
    
    return 0;
}
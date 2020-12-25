#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, s, k; cin >> n >> s >> k;
        map<int, bool> closedRes;
        for(int i = 0; i < k; i++) {
            int x; cin >> x;
            closedRes[x] = true;
        }

        int ansUp = 0;
        int i = s;
        while(closedRes[i] && i <= n)
            i++, ansUp++;
        if(i == n+1)
            ansUp = 1e9;
        int ansDown = 0;
        i = s;
        while(closedRes[i] && i >= 1)
            i --, ansDown ++;
        if(i == 0)
            ansDown = 1e9;
        
        cout << min(ansDown, ansUp) << "\n";
    }
    
    return 0;
}
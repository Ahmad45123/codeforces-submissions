#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int i = 0;
        int n = s.size()-1;
        while(i <= n && s[i] == '0')
            i ++;
        while(n >= i && s[n] == '0')
            n --;
        int ans = 0;
        for(; i <= n; i++) {
            if(s[i] == '0')
                ans ++;
        }
        cout << ans << "\n";
    }
    
    return 0;
}
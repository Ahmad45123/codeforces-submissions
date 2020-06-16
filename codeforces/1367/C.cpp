#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int prevOne = -1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                int diff = i-prevOne-1-k;
                if(prevOne != -1)
                    diff -= k;
                if(diff > 0)
                    ans += ceil(diff*1.0/(k+1));
                prevOne = i;
            }
        }
        int diff = n-prevOne-1;
        if(prevOne != -1)
            diff -= k;
        if(diff > 0)
            ans += ceil(diff*1.0/(k+1));
        cout << ans << "\n";
    }
    
    return 0;
}
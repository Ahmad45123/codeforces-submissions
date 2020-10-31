#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        int ans = 0;
        int extra = 0;
        int pos = n-1;
        while(pos >= 0) {
            int sz = 0;
            char el = s[pos];
            while(pos >= 0 && s[pos] == el) {
                pos --;
                sz ++;
            }
            ans ++;
            extra += sz-1;
            if(extra > 0) {
                extra --;
            } else {
                pos --;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string s; cin >> s;
    int n = s.size();
    if(n < 4) {
        cout << 0 << "\n";
        return 0;
    } else {
        ll ans = 0;
        int last = 0;
        for(int i = 3; i < n; i++) {
            if(s[i] == 'r' && s[i-1] == 'a' && s[i-2] == 'e' && s[i-3] == 'b') {
                int j = i-3-last;
                ans += (j+1)*(n-i);
                last = i-2;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
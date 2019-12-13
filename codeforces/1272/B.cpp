#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q; cin >> q;
    while(q--) {
        string s; cin >> s;
        int d = 0, u = 0, l = 0, r = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'R')
                r++;
            else if(s[i] == 'L')
                l++;
            else if(s[i] == 'D')
                d++;
            else if(s[i] == 'U')
                u++;
        }

        u = min(u, d), d = u;
        r = min(r, l), l = r;
        
        if(u == 0)  {
            r = min(r, 1);
            l = min(l, 1);;
        }
        if(r == 0) {
            u = min(u, 1);;
            d = min(d, 1);;
        }

        string ans = "";
        while(r--)
            ans += 'R';
        while(d--)
            ans += 'D';
        while(l--)
            ans += 'L';
        while(u--)
            ans += 'U';

        cout << ans.length() << "\r\n" << ans << "\r\n";
    }
    return 0;
}
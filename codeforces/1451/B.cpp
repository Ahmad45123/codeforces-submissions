#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        string s; cin >> s;
        while(q--) {
            int l, r; cin >> l >> r;
            l --, r --;
            bool foundLeft = false, foundRight = false;
            for(int i = l-1; i >= 0; i--) {
                if(s[i] == s[l])
                    foundLeft = true;
            }
            for(int i = r+1; i < n; i++) {
                if(s[i] == s[r])
                    foundRight = true;
            }
            cout << (foundRight || foundLeft ? "YES\n" : "NO\n");
        }
    }
    
    return 0;
}
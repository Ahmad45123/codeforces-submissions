#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        string ans = "";
        ans += s[0];
        for(int i = 1; i < n-1; i+=2) {
            ans += s[i];
        }
        ans += s[n-1];
        cout << ans << "\n";
    }
     
    return 0;
}
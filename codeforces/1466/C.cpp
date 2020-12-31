#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n = s.size();

        vector<bool> marked(n);
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1] && !marked[i-1]) {
                marked[i] = true;
            }
            if(i > 1 && s[i] == s[i-2] && !marked[i-2]) {
                marked[i] = true;
            }
        }

        int ans = 0;
        for(auto x : marked)
            ans += x;
        cout << ans << "\n";
    }
    
    
    return 0;
}
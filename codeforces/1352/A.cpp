#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        vector<int> ans;
        int tmp = 1;
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i]-'0' != 0)
                ans.push_back(tmp*(s[i]-'0'));
            tmp *= 10;
        }
        cout << ans.size() << "\n";
        for(auto &x : ans)
            cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}
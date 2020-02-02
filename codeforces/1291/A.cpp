#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;

void solve() {
    //First make it not divisible by 2
    while(s.length() > 0 && (s[s.length()-1]-'0') % 2 == 0) {
        s.pop_back();
    }

    //Loop and sum.
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        ans += s[i]-'0';
    }
    while(ans % 2 != 0) {
        int flag = false;
        string tmp = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i]-'0' % 2 != 0 && !flag) { //We need to skip this digit.
                flag = true;
                ans -= (s[i]-'0');
                continue;
            }
            tmp += s[i];
        }
        s = tmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> s;
        solve();
        while(s.length() > 0 && s[0] == '0')
            s = s.substr(1, s.length()-1);
        cout << (s.length() > 0 ? s : "-1") << "\n";
    }
    
    return 0;
}
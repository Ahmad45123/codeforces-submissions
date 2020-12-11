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
        bool bad = false;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1] && s[i] != '?') {
                bad = true;
                break;
            }
        }

        if(bad) {
            cout << "-1\n";
            continue;
        }

        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                bool used[3] = {false, false, false};
                if(i > 0)
                    used[s[i-1]-'a'] = true;
                if(i < n-1)
                    used[s[i+1]-'a'] = true;
                for(int j = 0; j < 3; j++)
                    if(!used[j]) {
                        s[i] = 'a'+j;
                        break;
                    }
            }
        }

        cout << s << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        string s; cin >> s;
        int i = 0, j = s.size()-1;
        while (i < s.size() && s[i] == '0')
            i ++;
        while(j >= 0 && s[j] == '0')
            j --;

        if(j < i) {
            cout << 0 << "\n";
            continue;
        }

        vector<pair<char, int>> tmp;
        int cnt = 1; i += 1;
        for(; i <= j; i++) {
            if(s[i] != s[i-1]) {
                tmp.push_back({s[i-1], cnt});
                cnt = 1;
            } else {
                cnt ++;
            }
        }
        tmp.push_back({s[j], cnt});
        
        ll ans = 0;
        bool prevActive = false;
        for(int x = 0; x < tmp.size(); x++) {
            int value = 0;
            if(tmp[x].first == '0') {
                if(x+1 < tmp.size())
                    value = min(a, tmp[x].second*b);
            } else {
                if(prevActive == false) {
                    prevActive = true;
                    value = a;
                }
            }
            ans += value;
        }

        cout << ans << "\n";
    }
    
    return 0;
}
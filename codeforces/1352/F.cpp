#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string getMixes(int n) {
    string tmp = "01";
    n --;
    bool alter = false;
    for(int i = 0; i < n; i++) {
        tmp += (alter ? '1' : '0');
        alter = !alter;
    }
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int zeros, mix, ones; cin >> zeros >> mix >> ones;
        if(mix == 1) {
            string ans = "";
            for(int i = 0; i < zeros+1; i++)
                ans += "0";
            for(int i = 0; i < ones+1; i++)
                ans += "1";
            cout << ans << "\n";
        } else if(mix == 0 && zeros == 0) {
            string ans = "";
            for(int i = 0; i < ones+1; i++)
                ans += "1";
            cout << ans << "\n";
        } else if(mix == 0 && ones == 0) {
            string ans = "";
            for(int i = 0; i < zeros+1; i++)
                ans += "0";
            cout << ans << "\n";
        } else {
            mix -= 1;
            string ans = getMixes(mix);
            if(ans[ans.size()-1] == '0') {
                for(int i = 0; i < zeros; i++)
                    ans += "0";
                for(int i = 0; i < ones+1; i++)
                    ans += "1";
            } else if(ans[ans.size()-1] == '1') {
                for(int i = 0; i < ones; i++)
                    ans += "1";
                for(int i = 0; i < zeros+1; i++)
                    ans += "0";
            }
            cout << ans << "\n";
        }
    }
    
    return 0;
}
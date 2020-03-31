#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    string s; cin >> s;
 
    ll ans = 0;
 
    for(char c = 'z'; c >= 'a'; c--) {
        bool flag = true;
        while(flag) {
            flag = false;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] != c) continue;
                if((i-1 >= 0 && s[i]-s[i-1] == 1) || (i+1 < s.size() && s[i]-s[i+1] == 1)) {
                    ans ++;
                    s.erase(s.begin() + i);
                    i --;
                    flag = true;
                }
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
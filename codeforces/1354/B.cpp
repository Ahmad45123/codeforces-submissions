#include <bits/stdc++.h>
#include <regex>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        int ones = 0;
        int twos = 0;
        int threes = 0;

        int ans = 1e9;

        int j = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1')
                ones ++;
            else if(s[i] == '2')
                twos ++;
            else if(s[i] == '3')
                threes ++;
            while(ones > 0 && twos > 0 && threes > 0 && j <= i) {
                ans = min(ans, i-j+1);
                if(s[j] == '1')
                    ones --;
                else if(s[j] == '2')
                    twos --;
                else if(s[j] == '3')
                    threes --;
                j++;
            }
        }

        cout << (ans == 1e9 ? 0 : ans) << "\n";
    }
    
    return 0;
}
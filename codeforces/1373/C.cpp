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
        int sm = 0;
        bool neg = false;
        for(int i = 0; i < n; i++) {
            if(s[i] == '+')
                sm ++;
            else if(s[i] == '-')
                sm --;
            if(sm < 0)
                neg = true;
        }

        if(!neg) {
            cout << n << "\n";
            continue;
        }

        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; i++) {
            if(s[i] == '+')
                prefix[i+1] = 1;
            else if(s[i] == '-')
                prefix[i+1] = -1;
        }
        for(int i = 1; i < n+1; i++) {
            prefix[i] += prefix[i-1];
        }

        ll mxVal = 0;
        ll ans = n;
        for(int i = 1; i < n+1; i++) {
            if(-prefix[i] > mxVal) {
                mxVal = -prefix[i];
                ans += i;
            }
        }

        cout << ans << "\n";

    }
    
    return 0;
}
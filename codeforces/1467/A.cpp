#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n == 1)
            cout << "9\n";
        else if(n == 2)
            cout << "98\n";
        else {
            string ans = "989";
            char c = '0';
            for(int i = 0; i < n-3; i++) {
                ans += c;
                c ++;
                if(c == '9'+1)
                    c = '0';
            }
            cout << ans << "\n";
        }
    }
    
    return 0;
}
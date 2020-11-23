#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        
        string first = "";
        string second = "";
        char tmp = '0';
        for(int i = 0; i < n; i++) {
            first += tmp;
            tmp = (tmp == '0' ? '1' : '0');
            second += tmp;
        }
        
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != first[i]) {
                ans1 ++;
                while(s[i] != first[i])
                    i ++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(s[i] != second[i]) {
                ans2 ++;
                while(s[i] != second[i])
                    i ++;
            }
        }

        cout << min(ans1, ans2) << "\n";
    }
    
    return 0;
}
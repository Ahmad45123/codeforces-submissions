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
        bool fnd = false;
        string look = "2020";
        int cntLeft = 0, cntRight = 0;
        for(int i = 0; i < 4; i++)
            if(s[i] == look[i])
                cntLeft ++;
            else
                break;
        look = "0202";
        for(int i = n-1, j = 0; j < 4; i--, j++)
            if(s[i] == look[j])
                cntRight ++;
            else break;
        
        cout << (cntLeft+cntRight >= 4 ? "YES\n" : "NO\n");
    }
    
    return 0;
}
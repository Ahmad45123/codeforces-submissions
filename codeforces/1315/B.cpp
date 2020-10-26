#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int a, b, p; cin >> a >> b >> p;
        string s; cin >> s;
        
        int pos = s.size()-1;
        for(int i = s.size()-2; i >= 0; i--) {
            if(s[i] != s[i+1] || i == s.size()-2) {
                int cst = 0;
                if(s[i] == 'A')
                    cst = a;
                else
                    cst = b;
                if(p-cst < 0) {
                    // pos = i;
                    break;
                }
                p -= cst;
            }
            pos = i;
        }

        cout << pos+1 << "\n";
    }
    
    return 0;
}
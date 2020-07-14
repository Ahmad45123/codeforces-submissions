#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int S = 0, R = 0, P = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'S') S++;
            else if(s[i] == 'P') P++;
            else if(s[i] == 'R') R++;
        }
        char c;
        if(S >= R && S >= P) {
            c = 'R';
        } else if(R >= S && R >= P) {
            c = 'P';
        } else if(P >= R && P >= S) {
            c = 'S';
        }
        for(int i = 0; i < s.size(); i++)
            s[i] = c;
        cout << s << "\n";
    }
    
    return 0;
}
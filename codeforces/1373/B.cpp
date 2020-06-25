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
        
        int ones = 0, zeros = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0')
                zeros++;
            if(s[i] == '1')
                ones++;
        }

        int total = min(zeros, ones);
        cout << (total % 2 == 0 ? "NET\n" : "DA\n");
    }
    
    return 0;
}
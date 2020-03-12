#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();

        int maxConsec = 0, cur = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') {
                cur ++;
            } else  {
                maxConsec = max(cur, maxConsec);
                cur = 0;
            }
        }
        maxConsec = max(cur, maxConsec);

        cout << maxConsec+1 << "\n";
    }
    
    return 0;
}
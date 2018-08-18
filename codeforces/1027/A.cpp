#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool bad = false;
        for(int i = 0; i < n/2; i++) {
            if(s[i]+1 != s[n-i-1]+1 
            && s[i]-1 != s[n-i-1]-1
            && s[i]-1 != s[n-i-1]+1
            && s[i]+1 != s[n-i-1]-1
            ) {
                bad = true;
                break;
            }
        }

        cout << (bad ? "NO" : "YES") << endl;
    }
    return 0;
}
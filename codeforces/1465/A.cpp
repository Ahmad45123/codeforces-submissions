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
        int charCnt = 0;
        int others  = 0;
        bool good = false;
        for(int i = n-1; i >= 0; i --) {
            if(s[i] == ')') {
                charCnt ++;
            } else {
                others = i+1;
                break;
            }
        }
        cout << (charCnt > others ? "Yes\n" : "No\n");
    }
    
    return 0;
}
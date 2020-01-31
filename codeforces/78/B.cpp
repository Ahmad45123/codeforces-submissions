#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string t = "ROYGBIV";
char getNextPossible(string cur) {
    for(int i = 0; i < 7; i++) {
        if(cur[cur.length()-1] != t[i] && cur[cur.length()-2] != t[i] && cur[cur.length()-3] != t[i]
        && cur[0] != t[i] && cur[1] != t[i] && cur[2] != t[i]) {
            return t[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    string cur = "ROY";
    
    while(cur.length() != n) {
        char x = getNextPossible(cur);
        cur += x;
    }

    cout << cur << "\n";

    return 0;
}
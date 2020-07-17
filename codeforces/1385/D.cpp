#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(string s, char c) {
    int n = s.size();

    if(n == 1) {
        return (s[0] == c ? 0 : 1);
    }

    int changesLeft = 0;
    int changesRight = 0;
    for(int i = 0; i < n/2; i++) {
        if(s[i] != c)
            changesLeft ++;
    }
    for(int i = n/2; i < n; i++) {
        if(s[i] != c)
            changesRight ++;
    }
    //if(changesLeft < changesRight) {
        return min(changesLeft+solve(s.substr(n/2), c+1), changesRight+solve(s.substr(0, n/2), c+1));
    /*} else {
        return changesRight+solve(s.substr(0, n/2), c+1);
    }*/
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        cout << solve(s, 'a') << "\n";
    }
    
    return 0;
}
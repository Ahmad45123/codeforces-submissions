#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string r, b; cin >> r >> b;
        ll scoreRed = 0, scoreBlue = 0;
        for(int i = 0; i < n; i++) {
            if(r[i] > b[i])
                scoreRed ++;
            if(b[i] > r[i])
                scoreBlue ++;
        }
        if(scoreBlue == scoreRed) cout << "EQUAL\n";
        else if(scoreRed > scoreBlue) cout << "RED\n";
        else cout << "BLUE\n";
    }
    
    return 0;
}
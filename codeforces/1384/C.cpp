#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        int moves = 0;

        for(int i = 0; i < n; i++) {
            if(b[i] < a[i]) {
                moves = -1;
                break;
            }
        }
        if(moves == -1) {
            cout << "-1\n";
            continue;
        }

        for(char c = 'a'; c <= 'z'; c++) {
            char changeTo = 'z';
            bool fnd = false;
            for(int i = 0; i < n; i++) {
                if(a[i] == c && a[i] != b[i]) {
                    changeTo = min(changeTo, b[i]);
                    fnd = true;
                }
            }
            if(fnd) {
                moves ++;
                for(int i = 0; i < n; i++) {
                    if(a[i] == c && a[i] != b[i]) {
                        a[i] = changeTo;
                    }
                }
            }
        }

        cout << moves << "\n";
    }
    
    return 0;
}
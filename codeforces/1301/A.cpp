#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string a, b, c; cin >> a >> b >> c;
        bool good = true;
        for(int i = 0; i < a.length(); i++) {
            if(c[i] != a[i] && c[i] != b[i])
            {
                good = false;
                break;
            }
        }
        
        if(good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int x, y, z; cin >> x >> y >> z;
        if(x == y && x >= z) {
            cout << "YES\n";
            cout << x << " " << z << " 1\n";
        } else if(x == z && x >= y) {
          cout << "YES\n";
         cout << x << " " << y << " 1\n";  
        } else if(y == z && y >= x) {
cout << "YES\n";
            cout << y << " " << x << " 1\n";
        } else {
            cout << "NO\n";

        }
    }
    
    return 0;
}
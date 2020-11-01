#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(a == d && b == c)
            cout << a+c << "\n";
        else if(a == d)
            cout << c+d << "\n";
        else if(b == c)
            cout << a+b << "\n";
        else
            cout << max(a+b, c+d) << "\n";
    }
    
    return 0;
}
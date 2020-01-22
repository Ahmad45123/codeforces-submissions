#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int a, b, c, n; cin >> a >> b >> c >> n;
        int req = 0;
        if(a >= b && a >= c) {
            req = (a-b)+(a-c);
        }
        else if(b >= a && b >= c) {
            req = (b-a)+(b-c);
        }
        else if(c >= a && c >= b) {
            req = (c-a)+(c-b);
        }
        
        if(req <= n && (n-req)%3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
 
    return 0;
}
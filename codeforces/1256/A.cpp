#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll a, b, n, S; cin >> a >> b >> n >> S;
        ll req1 = S % n;
        ll reqn = (S - req1)/n;
        
        if(a*n+b >= S && S%n <= b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll n, m; cin >> n >> m;
    cout << power(power(2, m, M)-1, n, M) << "\n";
    
    return 0;
}
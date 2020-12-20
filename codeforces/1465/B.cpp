#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool test(ll x) {
    ll temp = x; 
    bool good = true;
    while (x) { 
        int k = x % 10; 
  
        // check if K divides N 
        if (k != 0 && temp % k != 0) { 
            good = false; 
            break;
        }
  
        x /= 10; 
    } 
  
    return good; 
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        while(!test(n))
            n++;
        cout << n << "\n";
    }   
    
    return 0;
}
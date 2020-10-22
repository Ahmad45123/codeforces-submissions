#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int getLeastDiv(int x) {
    for(int i = 2; i <= sqrt(x); i++) {
        if(x % i == 0)
            return i;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n, k; cin >> n >> k;
        int divisor = getLeastDiv(n);
        while(divisor != 2 && k > 0) {
            n += divisor;
            k --;
            divisor = getLeastDiv(n);
        }
        n += k*2;
        cout << n << "\n";
    }
    
    return 0;
}
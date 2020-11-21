#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int largestDivisor(int n) {
    int sqrtn = (int)sqrt(n);
    for(int i = 2; i <= sqrtn; i++) {
        if(n % i == 0) {
            return n/i;
        }
    }
    return 0; 
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = 0;

        if(n <= 3) {
            ans = n-1;
        }
        else if(n % 2 == 0) {
            ans = 2;
        } else {
            ans = 3;
        }

        cout << ans << "\n";
    }
    
    return 0;
}
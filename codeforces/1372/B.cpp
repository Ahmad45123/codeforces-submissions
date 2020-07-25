#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int largestFactor = 1;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) {
                largestFactor = max(largestFactor, i);
                largestFactor = max(largestFactor, n/i);
            }
        }
        cout << largestFactor << " " << n-largestFactor << "\n";
    }
    
    return 0;
}
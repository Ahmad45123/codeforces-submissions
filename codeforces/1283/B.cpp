#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        if(n%k == 0) {
            cout << n << "\n";
        } else {
            int a = n/k;
            int b = a+1;
            cout <<  min(n, b*(k/2)+a*(k-k/2)) << "\n";
        }
    }
    
    return 0;
}
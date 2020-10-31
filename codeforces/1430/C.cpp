#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << "2\n";
        int prev = n;
        for(int i = n-1; i >= 1; i--) {
            cout << prev << " " << i << "\n";
            prev = ceil((i+prev)*1.0/2.0);
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n % 2 == 0) {
            for(int i = n; i >= 1; i--)
                cout << i << " ";
        } else {
            for(int i = n; i > n/2+1; i--)
                cout << i << " ";
            cout << n/2 << " " << n/2+1 << " ";
            for(int i = n/2 - 1; i >= 1; i--)
                cout << i << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
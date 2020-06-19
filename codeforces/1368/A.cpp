#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int a, b, n; cin >> a >> b >> n;
        int steps = 0;
        while(a <= n && b <= n) {
            if(a > b) {
                b += a;
            } else {
                a += b;
            }
            steps++;
        }
        cout << steps << "\n";
    }
    
    return 0;
}
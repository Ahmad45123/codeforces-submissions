#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        bool done = false;

        for(int a = 0; a <= n; a += 3) {
            for(int b = 0; b <= n; b += 5) {
                for(int z = 0; z <= n; z += 7) {
                    if(a+b+z == n) {
                        cout << a/3 << " " << b/5 << " " << z/7 << "\n";
                        done = true;
                        break;
                    }
                }
                if(done)
                    break;
            }
            if(done)
                break;
        }

        if(!done)
            cout << "-1\n";
    }
    
    return 0;
}
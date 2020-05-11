#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int attempts[][7] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 1},
        {1, 1, 1},
    };

    int t; cin >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;
        if(a<b)
            swap(a,b);
         if(a<c)
            swap(a,c);
         if(b<c)
            swap(b,c);

        int ans = 0;
        for(int i = 0; i < 7; i++) {
            if(a-attempts[i][0] >= 0 && b-attempts[i][1] >= 0 && c-attempts[i][2] >= 0) {
                a -= attempts[i][0];
                b -= attempts[i][1];
                c -= attempts[i][2];
                ans ++;
            }
        }
        cout  << ans << "\n";
    }
    
    return 0;
}
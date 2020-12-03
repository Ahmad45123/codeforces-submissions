#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, l, r; cin >> n >> l >> r;

    ll mn = 0, mx = 0;
    ll cur = 1;
    int cnt = 1;
    for(int i = 0; i <= n-l; i++) {
        mn += 1;
    }
    for(int i = 0; i < n; i++) {
        if(i < l && cur > 1)
            mn += cur;
        
        mx += cur;
        if(cnt < r) {
            cnt ++;
            cur *= 2;
        }
    }

    cout << mn << " " << mx << "\n";
    
    return 0;
}
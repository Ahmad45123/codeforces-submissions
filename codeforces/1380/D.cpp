#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    ll x, k, y; cin >> x >> k >> y;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &x : a)
        cin >> x;
    
    for (auto &x : b)
        cin >> x;
    
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[j])
            j ++;
    }

    if(j != m) {
        cout << -1 << "\n";
        return 0;
    }

    ll ans = 0;

    j = 0;
    int prevI = -1;
    int curMx = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[j]) {
            int sz = i-prevI-1;
            ll tmp = x*1LL*(sz/k);
            bool good = false;
            if(sz % k != 0 && sz / k != 0) {
                ll rem = sz%k;
                tmp += rem*y;
                good = true;
            } else if(sz % k == 0) {
                good = true;
            } else {
                tmp = 1e15;
            }

            if(curMx < a[i] || (prevI >= 0 && curMx < a[prevI])) {
                tmp = min(tmp, y*sz*1LL);
                good = true;
            } else if(sz > k) {
                tmp = min(tmp, x+y*(sz-k));
                good = true;
            }

            if(!good) {
                cout << -1 << "\n";
                return 0;
            }

            ans += tmp;
            j ++;
            prevI = i;
            curMx = 0;
        } else {
            curMx = max(curMx, a[i]);
        }
    }

    bool good = false;
    int sz = n-prevI-1;
    ll tmp = x*1LL*(sz/k);
    if(sz % k != 0 && sz / k != 0) {
        ll rem = sz%k;
        tmp += rem*y;
        good = true;
    } else if(sz % k == 0) {
        good = true;
    } else {
        tmp = 1e15;
    }

    if(curMx < a[prevI]) {
        tmp = min(tmp, y*sz*1LL);
        good = true;
    } else if(sz > k) {
        tmp = min(tmp, x+y*(sz-k));
        good = true;
    }

    ans += tmp;

    if(!good) {
        cout << -1 << "\n";
        return 0;
    }

    cout << ans << "\n";
    
    return 0;
}
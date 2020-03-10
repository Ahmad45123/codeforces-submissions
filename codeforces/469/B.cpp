#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

bool overlap(int a, int b, int c, int d) {
    if(a <= c && b >= c)
        return true;
    if(a >= c && a <= d)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int p, q, l, r; cin >> p >> q >> l >> r;
    vector<pair<int, int>> first(p);
    vector<pair<int, int>> second(q);
    for(int i = 0; i < p; i++)
    {
        int a, b; cin >> a >> b;
        first[i] = {a, b};
    }
    for(int i = 0; i < q; i++)
    {
        int a, b; cin >> a >> b;
        second[i] = {a, b};
    }
    
    ll ans = 0;

    for(int t = l; t <= r; t++) {
        for(int i = 0; i < q; i++) {
            bool flag = false;
            for(int j = 0; j < p; j++) {
                if(overlap(second[i].first+t, second[i].second+t, first[j].first, first[j].second)) {
                    ans ++;
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
    }

    cout << ans;
    return 0;
}
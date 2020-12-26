#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll x0, y0, ax, ay, bx, by; cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, time; cin >> xs >> ys >> time;

    vector<pair<ll, ll>> points;
    while(x0 <= xs+time && y0 <= ys+time) {
        points.push_back({x0, y0});
        x0 = ax*x0+bx;
        y0 = ay*y0+by;
    }
    
    ll realAns = 0;
    for(int j = 0; j < points.size(); j++) {
        ll ans = 1;
        vector<bool> vis(points.size());
        vis[j] = true;
        ll t = time-(abs(points[j].first-xs)+abs(points[j].second-ys));
        if(t < 0) continue;
        ll xi = points[j].first;
        ll yi = points[j].second;
        while(true) {
            ll initTime = 1e18;
            int idx = -1;
            for(int i = 0; i < points.size(); i++) {
                if(vis[i]) continue;
                if(abs(points[i].first-xi)+abs(points[i].second-yi) < initTime) {
                    initTime = abs(points[i].first-xi)+abs(points[i].second-yi);
                    idx = i;
                }
            }
            if(idx == -1) break;
            if(initTime <= t) {
                t -= initTime;
                xi = points[idx].first;
                yi = points[idx].second;
                vis[idx] = true;
                ans ++;
            } else {
                break;
            }
        }
        realAns = max(realAns, ans);
    }

    cout << realAns << "\n";
    return 0;
}
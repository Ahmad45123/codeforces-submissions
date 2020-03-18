#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int vp, vd, t, f, c; cin >> vp >> vd >> t >> f >> c;
    int ans = 0;
    double timeToWait = t;
    double prevDist = 0;

    if(vp > vd) {
        cout << 0 << "\n";
        return 0;
    }

    while(true) {
        double x = (vp*timeToWait*1.0+prevDist)/(vd*1.0-vp);
        prevDist += vp*(x+timeToWait);
        if(prevDist >= c)
            break;
        ans ++;
        timeToWait = x+f;
    }

    cout << ans << "\n";
    return 0;
}
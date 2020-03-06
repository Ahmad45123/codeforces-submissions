#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isGood(int a, int b, double y) {
    double x = (b+y-a)/(2*y);
    if(x > 1.0)
        return false;
    double first = x*y;
    if(floor(first) != first)
        return false;
    if(first+a == (y-first)+b)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<ll> sums;
    sums.push_back(1);
    ll cur = 2;
    while(*(sums.end()-1) < 1e10) {
        sums.push_back(*(sums.end()-1) + cur);
        cur ++;
    }
    
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        if(a == b) {
            cout << 0 << "\n";
            continue;
        }
        if(a > b)
            swap(a, b);

        int good = -1;
        for(int i = 0; i < sums.size(); i++) {
            if(isGood(a, b, sums[i])) {
                good = i+1;
                break;
            }
        }
        cout << good << "\n";
    }
    return 0;
}
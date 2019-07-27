#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);

    int n, b, d; cin >> n >> b >> d;
    int res = 0, cur = 0;

    while(n--) {
        int t; cin >> t;
        if(t <= b) {
            cur += t;
        }
        if(cur > d) {
            res ++;
            cur = 0;
        }
    }

    cout << res;

    int test123; cin >> test123; return 0;
}
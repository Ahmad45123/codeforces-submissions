#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

#define M 1000000007

ll calc(ll n) {
    return (n*(n+1))/2;
}

int c[2][200001];

int solve(int n, int red, int green) {
    for(int i = 0; i <= red; i++) {
        c[0][i] = 1;
    }

    for(int cur = 1; cur <= n; cur++) {
        for(int r = 0; r <= red; r++) {
            c[cur%2][r] = 0;
            if(r >= cur)
                c[cur%2][r] += c[(cur-1)%2][r-cur]%M;
            int g = green-(calc(n)-calc(cur)-red+r);
            if(g >= cur)
                c[cur%2][r] += c[(cur-1)%2][r]%M;
        }
    }

    return c[n%2][red]%M;
}

int main()
{
    int red, green; cin >> red >> green;

    /*//binary search to find start
    ll sum = red+green;
    ll l = 1, r = 1e9;
    while(l < r) {
        ll mid = (l+r)/2;
        if(calc(mid) > sum)
            r = mid-1;
        else if(calc(mid) < sum)
            l = mid+1;
    }

    if(calc(l) > sum)
        l--;*/

    int l = (-1 + sqrt(1+8*(red+green)))/2;

    memset(c, 0, sizeof c);

    int a = solve(l, red, green);
    cout << a;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);

    int a, b; cin >> a >> b;
    int r = 0;

    while(a <= b) {
        r ++;
        a += a*2;
        b += b;
    }
    cout << r;

    int test123; cin >> test123; return 0;
}
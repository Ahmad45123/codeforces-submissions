#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int ans = 0;
    while(n--) {
        int a, b, c; cin >> a >> b >> c;
        if(a + b + c == 2 || a + b + c == 3)
            ans ++;
    }
    cout << ans;

    int test123; cin >> test123; return 0;
}
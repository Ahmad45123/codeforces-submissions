#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<ll> ans(1001);
    ans[0] = 1;
    ans[1] = 4;
    ans[2] = 4;
    ans[3] = 8;
    for(int i = 4; i <= 1000; i++) {
        if(i % 2 == 0) ans[i] = ans[i-1];
        else ans[i] = ans[i-2]+4;
    }
    for(int i = 3; i <= 1000; i++) {
        if(i % 2 == 0) ans[i] += ans[i-4];
        else ans[i] += ans[i-2];
    }
    cout << ans[n] << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<int> ans(1e6+1, 0);
    ans[1] = 1;
    vector<bool> prime(1e6+1, true);
    for(ll i = 2; i <= 1e6; i++) {
        if(prime[i]) {
            ans[i] += 1;
            if(i*i <= 1e6)
                ans[i*i] -= 1;
            for(ll x = i+i; x <= 1e6; x += i)
                prime[x] = false;
        }
    }

    for(int i = 1; i <= 1e6; i++)
        ans[i] += ans[i-1];
    
    int t; cin >> t;
    while(t--) {    
        int n; cin >> n;
        cout << ans[n] << "\n";
    }
    
    return 0;
}
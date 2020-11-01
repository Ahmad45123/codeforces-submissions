#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(int &x : arr) {
        cin >> x;
    }

    if(n <= m) {
        int ans = 1;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                ans *= abs(arr[j]-arr[i])%m;
                ans %= m;
            }
        }
        cout << ans << "\n";
    } else {
        cout << "0\n";
    }

    
    return 0;
}
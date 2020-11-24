#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            sum += tmp;
        }
        cout << (sum == m ? "YES\n" : "NO\n");
    }
    
    return 0;
}
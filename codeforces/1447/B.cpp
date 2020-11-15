#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<ll>> arr(n, vector<ll>(m));
        ll sm = 0;
        ll neg = 0;
        ll minValue = 1e9;
        bool zero = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                cin >> arr[i][j];
                sm += abs(arr[i][j]);
                minValue = min(minValue, abs(arr[i][j]));
                if(arr[i][j] < 0) {
                    neg ++;
                }
                if(arr[i][j] == 0)
                    zero = true;
            }

        if(neg % 2 != 0 && !zero) {
            sm -= 2*minValue;
        }

        cout << sm << "\n";
    }
    
    return 0;
}
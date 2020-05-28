#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<vector<char>> arr(n, vector<char>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) 
                cin >> arr[i][j];
        
        ll allCost = 0;
        for(int i = 0; i < n; i++) {
            ll rowCost = 0;
            int dotCount = 0;
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == '.') {
                    dotCount ++;
                } else {
                    if(dotCount == 0) continue;
                    rowCost += min(dotCount*x, (dotCount % 2 == 0 ? (dotCount/2)*y : x+(dotCount/2)*y));
                    dotCount = 0;
                }
            }
            if(dotCount > 0) {
                rowCost += min(dotCount*x, (dotCount % 2 == 0 ? (dotCount/2)*y : x+(dotCount/2)*y));
            }
            allCost += rowCost;
        }

        cout << allCost << "\n";
    }
    
    return 0;
}
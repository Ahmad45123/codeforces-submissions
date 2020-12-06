#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second;
        
        bool pos = false;

        for(int i = 0; i < n; i++) {
            int mxDist = 0;
            for(int j = 0; j < n; j++) {
                mxDist = max(mxDist, abs(arr[i].first-arr[j].first)+abs(arr[i].second-arr[j].second));
            }
            if(mxDist <= k)
                pos = true;
        }

        if(pos) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}
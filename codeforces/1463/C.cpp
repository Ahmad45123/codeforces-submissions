#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int, int>> arr(n);
        vector<ll> poses(n, 0);
        for(auto &x : arr)
            cin >> x.first >> x.second;
        
        ll curPos = 0, curTime = 0;
        bool isRight = false;
        int ans = 0;
        for(int i = 0; i < n; i++) {            
            if(i > 0) {
                ll pos = (isRight ? curPos-max(0LL, curTime-arr[i].first) : curPos+max(0LL, curTime-arr[i].first));
                poses[i] = pos;
            }
            
            if(arr[i].first >= curTime) {
                if(arr[i].second > curPos) isRight = true;
                else isRight = false;
                curTime += abs(curTime-arr[i].first)+abs(arr[i].second-curPos);
                curPos = arr[i].second;
            }
        }

        poses.push_back(curPos);
        for(int i = 1; i <= n; i++) {
            if(poses[i] >= poses[i-1] && arr[i-1].second >= poses[i-1] && arr[i-1].second <= poses[i]) {
                ans ++;
            } else if(poses[i] <= poses[i-1] && arr[i-1].second <= poses[i-1] && arr[i-1].second >= poses[i]) {
                ans ++;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll convertAndReturn(int i, int j, int &n, int &m, vector<vector<int>> &arr) {
    vector<pair<int, int>> toCheck;
    toCheck.push_back({i, j});
    toCheck.push_back({n-i-1, j});
    toCheck.push_back({i, m-j-1});
    toCheck.push_back({n-i-1, m-j-1});

    vector<int> nums;

    for(auto x : toCheck) {
        nums.push_back(arr[x.first][x.second]);
    }
    sort(nums.begin(), nums.end());

    ll ans = 0;
    int target = nums[2];
    for(auto x : toCheck) {
        ans += abs(target-arr[x.first][x.second]);
        arr[x.first][x.second] = target;
    }

    return ans;
} 

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> arr[i][j];
        
        ll ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans += convertAndReturn(i, j, n, m, arr);
            
        cout << ans << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> nums(n+1);
    bool vis[2*100000+2] = {};
    
    vector<int> zeroPos;
    vector<int> missing;

    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        vis[nums[i]] = true;
        if(nums[i] == 0)
            zeroPos.push_back(i);
    }
    
    for(int i = 1; i <= n; i++) {
        if(vis[i] != true) 
            missing.push_back(i);
    }

    for(int i = 0; i < missing.size(); i++) {
        if(zeroPos[i] == missing[i]) {
            if(i == 0) swap(zeroPos[i], zeroPos[i+1]);
            else swap(zeroPos[i], zeroPos[i-1]);
        }
    }

    for(int i = 0; i < missing.size(); i++) {
        nums[zeroPos[i]] = missing[i];
    }

    for(int i = 1; i <= n; i++) {
        cout << nums[i] << " ";
    }
    
    return 0;
}
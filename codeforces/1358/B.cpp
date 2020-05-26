#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(auto &x : arr)
            cin >> x;
        
        sort(arr.begin(), arr.end());

        int curGrannies = 1;
        int tmpCount = 0;
        int maxNeeded = 0;
        for(int curI = 0;curI < n; curI++) {
            maxNeeded = max(maxNeeded, arr[curI]);
            if(maxNeeded <= tmpCount+curGrannies) {
                curGrannies += tmpCount+1;
                tmpCount = -1;
                maxNeeded = 0;
            }
            tmpCount ++;
        }

        cout << curGrannies << "\n";
    }
    
    return 0;
}
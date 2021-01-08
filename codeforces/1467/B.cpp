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
        for(int &x : arr)
            cin >> x;
        if(n <= 3) {
            cout << "0\n";
            continue;
        }

        int mxRem = 0;
        for(int i = 1; i < n-1; i++) {
            int tmp = 0;
            int cur = arr[i];
            if((cur > arr[i-1] && cur > arr[i+1]) || (cur < arr[i-1] && cur < arr[i+1])) {
                tmp ++;
            }
            if(i+2 < n && ((arr[i+1] > arr[i+2] && arr[i+1] > cur) || (arr[i+1] < arr[i+2] && arr[i+1] < cur))) {
                tmp ++;
            }
            if(i-2 >= 0 && ((arr[i-1] > arr[i-2] && arr[i-1] > cur) || (arr[i-1] < arr[i-2] && arr[i-1] < cur))) {
                tmp ++;
            }
            
            cur = arr[i-1];
            int leftChanged = 0;
            if((cur > arr[i-1] && cur > arr[i+1]) || (cur < arr[i-1] && cur < arr[i+1])) {
                leftChanged ++;
            }
            if(i+2 < n && ((arr[i+1] > arr[i+2] && arr[i+1] > cur) || (arr[i+1] < arr[i+2] && arr[i+1] < cur))) {
                leftChanged ++;
            }
            if(i-2 >= 0 && ((arr[i-1] > arr[i-2] && arr[i-1] > cur) || (arr[i-1] < arr[i-2] && arr[i-1] < cur))) {
                leftChanged ++;
            }
            
            cur = arr[i+1];
            int rightChanged = 0;
            if((cur > arr[i-1] && cur > arr[i+1]) || (cur < arr[i-1] && cur < arr[i+1])) {
                rightChanged ++;
            }
            if(i+2 < n && ((arr[i+1] > arr[i+2] && arr[i+1] > cur) || (arr[i+1] < arr[i+2] && arr[i+1] < cur))) {
                rightChanged ++;
            }
            if(i-2 >= 0 && ((arr[i-1] > arr[i-2] && arr[i-1] > cur) || (arr[i-1] < arr[i-2] && arr[i-1] < cur))) {
                rightChanged ++;
            }

            mxRem = max(mxRem, tmp-min(leftChanged, rightChanged));
        }

        int ans = 0;
        for(int i = 1; i < n-1; i++) {
            if((arr[i] > arr[i-1] && arr[i] > arr[i+1]) || (arr[i] < arr[i-1] && arr[i] < arr[i+1])) {
                ans ++;
            }
        }

        cout << ans-mxRem << "\n";
    }
    
    return 0;
}
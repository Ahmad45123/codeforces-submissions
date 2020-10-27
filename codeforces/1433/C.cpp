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
        bool same = true;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(i > 0 && arr[i] != arr[i-1])
                same = false;
        }

        if(same) {
            cout << "-1\n";
            continue;
        }

        int mx = *max_element(arr.begin(), arr.end());
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] == mx) {
                if((i > 0 && arr[i-1] < mx) || (i+1 < n && arr[i+1] < mx)) {
                    ans = i+1;
                }
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}
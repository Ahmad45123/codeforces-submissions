#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for(auto &x : arr)
            cin >> x;
        
        int minel = *min_element(arr.begin(), arr.end());
        minel += k;

        bool bad = false;

        for(int i = 0; i < n; i++) {
            if(abs(arr[i]-minel) > k) {
                bad = true;
                break;
            }
        }

        if(bad)
            cout << "-1\n";
        else
            cout << minel << "\n";

    }
    
    return 0;
}
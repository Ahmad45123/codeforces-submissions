#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> arr(n);
        //unordered_map<int, bool> unique;
        ll count = 0;
        ll mn = 1e9, mx = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for(int i = 0; i < n; i++) {
            if(arr[i] != -1 /*&& !unique[arr[i]]*/) {
                if((i+1 < n && arr[i+1] == -1) || (i-1 >= 0 && arr[i-1] == -1)) {
                    mn = min(arr[i], mn);
                    mx = max(arr[i], mx);
                    count ++;
                    //unique[arr[i]] = true;
                }
            }
        }

        if(count == 0) {
            cout << "0 0\n";
            continue;
        }

        ll k = ceil((mn+mx)/2.0);
        ll m = 0;

        for(int i = 1; i < n; i++) {
            if(arr[i] == -1 && arr[i-1] == -1) {}
            else if(arr[i] == -1)
                m = max(m, abs(k-arr[i-1]));
            else if(arr[i-1] == -1)
                m = max(m, abs(arr[i]-k));
            else
                m = max(m, abs(arr[i]-arr[i-1]));
        }

        cout << m << " " << k << "\n"; 
    }
    
    return 0;
}
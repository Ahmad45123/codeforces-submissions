#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; ll k; cin >> n >> k;
        vector<int> arr(n);
        int mx = -1e9;
        for(int &x : arr) {
            cin >> x;
            mx = max(x, mx);
        }

        for(int i = 0; i < n; i++) {
            arr[i] = mx-arr[i];
        }
        vector<int> second = arr;
        mx = -1e9;
        for(int i = 0; i < n; i++) {
            mx = max(mx, second[i]);
        }
        for(int i = 0; i < n; i++) {
            second[i] = mx-second[i];
        }

        if(k % 2 == 0) {
            for(int i = 0; i < n; i++)
                cout << second[i] << " ";
            cout << "\n";
        } else {
            for(int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << "\n";
        }
    }
    
    return 0;
}
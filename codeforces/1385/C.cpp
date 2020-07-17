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
        
        if(n == 1 || n == 2) {
            cout << 0 << "\n";
            continue;
        }

        int max = 0;

        for(int i = n-2; i >= 0; i--) {
            if(arr[i] < arr[i+1]) {
                max = i;
                break;
            }
        }

        int ans = 0;

        if(max-1 >= 0)
            for(int i = max-1; i >= 0; i--) {
                if(arr[i] > arr[i+1]) {
                    ans = i+1;
                    break;
                }
            }

        cout << ans << "\n";
    }
    
    return 0;
}
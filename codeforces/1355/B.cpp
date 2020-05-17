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
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int exp = arr[i];
            int counter = 0;
            int j = i;
            while(counter != exp && j < n) {
                if(arr[j] > exp) {
                    exp = arr[j];
                }
                counter ++;
                j ++;
            }
            if(counter >= exp)
                ans ++;
            i = j-1;
        }
        cout << ans << "\n";
    }
    return 0;
}
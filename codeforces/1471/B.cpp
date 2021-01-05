#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;

        vector<int> flag(n, 0);
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            int tmp = arr[i];
            sum += arr[i];
            while(tmp % x == 0) {
                tmp /= x;
                cnt ++;
            }
            flag[i] = cnt;
        }
        ll mn = *min_element(flag.begin(), flag.end());
        for(int i = 0; i < n; i++)
            sum += mn*arr[i];
        for(int i = 0; i < n; i++) {
            if(flag[i] == mn) {
                break;
            }
            sum += arr[i];
        }
         
        cout << sum << "\n";
    }
    
    return 0;
}
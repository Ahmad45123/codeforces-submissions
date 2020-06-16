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
        int zeros = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            if(arr[i] == 0)
                zeros ++;
        }

        if(zeros == 0 && sum != 0) {
            cout << 0 << "\n";
        } else if(zeros == 0 && sum == 0) {
            cout << 1 << "\n";
        } else if(zeros > 0) {
            if(sum >= 0)
                cout << zeros << "\n";
            else {
                if(-sum == zeros) {
                    cout << zeros+1 << "\n";
                } else {
                    cout << zeros << "\n";
                }
            }
        }
    }
    
    return 0;
}
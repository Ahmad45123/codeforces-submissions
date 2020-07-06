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

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                if(arr[i] < 0)
                    arr[i] *= -1;
            } else {
                if(arr[i] > 0)
                    arr[i] *= -1;
            }
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}
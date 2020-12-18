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
        for(int &x : arr) {
            cin >> x;
        }
        
        ll sumA = 0;
        ll sumB = 0;
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 0)
                sumA += arr[i-1];
            else
                sumB += arr[i-1];
        }

        if(sumA < sumB) {
            for(int i = 1; i <= n; i++) {
                if(i % 2 == 0) cout << "1 ";
                else cout << arr[i-1] << " ";
            }
        } else {
            for(int i = 1; i <= n; i++) {
                if(i % 2 != 0) cout << "1 ";
                else cout << arr[i-1] << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}
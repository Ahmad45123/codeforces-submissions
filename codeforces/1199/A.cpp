#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, x, y; cin >> n >> x >> y;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    
    for(int i = 0; i < n; i++) {
        bool good = true;
        for(int j = i-1; j >= 0 && j >= i-x; j--) {
            if(arr[j] <= arr[i]) {
                good = false;
                break;
            }
        }
        for(int j = i+1; j < n && j <= i+y; j++) {
            if(arr[j] <= arr[i]) {
                good = false;
                break;
            }
        }
        if(good) {
            cout << i+1 << "\n";
            return 0;
        }
    }
    
    return 0;
}
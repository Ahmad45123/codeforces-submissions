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
        for(int &x : arr)   cin >> x;
        int l = 0, r = n-1;
        bool ok = false;
        while(l <= r) {
            if(!ok){
                cout << arr[l] << " ";
                l ++;
            } else {
                cout << arr[r] << " ";
                r --;
            }
            ok = !ok;
        }
        cout << "\n";
    }
    
    return 0;
}
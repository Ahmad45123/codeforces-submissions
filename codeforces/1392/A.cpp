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
        for(auto &x : arr)
            cin >> x;
        
        if(n == 1) {
            cout << "1\n";
            continue;
        }

        bool same = true;

        for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i-1]) {
                same = false;
                break;
            }
        }

        if(!same)
            cout << "1\n";
        else
            cout << n << "\n";
    }
    
    return 0;
}
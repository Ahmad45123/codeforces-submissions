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
        int nOdds = 0;
        int nEvens = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] % 2 == 0)
                nEvens ++;
            else
                nOdds ++;
        }
        
        if(nOdds % 2 != 0 || (nEvens > 0 && nOdds > 0))
            cout << "YES\n";
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
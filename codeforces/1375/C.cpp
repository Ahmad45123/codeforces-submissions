#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> arr(n+1);
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            arr[x] = i;
        }

        for(int i = n; i >= 1; i--) {
            if(arr[i] == n) {
                cout << "YES\n";
                break;
            /*} else if(arr[i] == 1 && i == 1) {
                cout << "YES\n";
                break;*/
            } else if(arr[i] == 1 && i != 1) {
                cout << "NO\n";
                break;
            }
        }
    }
    
    
    return 0;
}
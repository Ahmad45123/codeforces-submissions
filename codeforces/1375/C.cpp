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

        bool bad = true;
        for(int i = n; i >= 1; i--) {
            if(arr[i] == n) {
                bad = false;
                break;
            } else if(arr[i] == 1 && i == 1) {
                bad = false;
                break;
            } else if(arr[i] == 1 && i != 1) {
                bad = true;
                break;
            }
        }

        cout << (bad ? "NO\n" : "YES\n");
    }
    
    
    return 0;
}
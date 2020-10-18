#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve () {
    int n; cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
        
    if(arr[n-2][n-1] == arr[n-1][n-2]) {
        int ans = 0;
        int v = arr[n-2][n-1]-'0';
        v = !v;
        char c = '0'+v;
        if(arr[0][1] != c) {
            ans ++;
        }
        if(arr[1][0] != c) {
            ans ++;
        }
        cout << ans << "\n";
        if(arr[0][1] != c) {
            cout << "1 2\n";
        }
        if(arr[1][0] != c) {
            cout << "2 1\n";
        }
        return;
    } else if(arr[0][1] == arr[1][0]) {
        int ans = 0;
        int v = arr[0][1]-'0';
        v = !v;
        char c = '0'+v;
        if(arr[n-1][n-2] != c) {
            ans ++;
        }
        if(arr[n-2][n-1] != c) {
            ans ++;
        }
        cout << ans << "\n";
        if(arr[n-1][n-2] != c) {
            cout << n << " " << n-1 << "\n";
        }
        if(arr[n-2][n-1] != c) {
            cout << n-1 << " " << n << "\n";
        }
        return;
    } else {
        int ans = 2;
        cout << ans << "\n";
        if(arr[0][1] != '0') {
            cout << "1 2\n";
        } else if(arr[1][0] != '0') {
            cout << "2 1\n";
        }

        if(arr[n-1][n-2] != '1') {
            cout << n << " " << n-1 << "\n";
        } else if(arr[n-2][n-1] != '1') {
            cout << n-1 << " " << n << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        solve ();
    }
    
    return 0;
}
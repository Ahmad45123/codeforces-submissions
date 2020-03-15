#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<string> arr(n);
    for(string &i : arr)
        cin >> i;
    
    vector<int> spos(n);

    bool bad = false;
    for(int i = 0; i < n; i++) {
        bool gotToS = false;
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 'S')
                gotToS = true, spos[i] = j;
            if(arr[i][j] == 'G' && gotToS == true) {
                bad = true;
            }
        }
    }

    if(bad) {
        cout << "-1\n";
        return 0;
    }

    int ans = 0;
    bool vis[1001] = {};
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(arr[i][j] == 'G') {
                if(!vis[spos[i]-j])
                    vis[spos[i]-j] = true, ans ++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
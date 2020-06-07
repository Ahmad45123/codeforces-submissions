#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<char>> arr(n, vector<char>(m));
        int nmgood = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                cin >> arr[i][j];
                if(arr[i][j] == 'G')
                    nmgood ++;
            }
        
        if(nmgood == 0) {
            cout << "Yes\n";
            continue;
        }

        bool allBlocked = true;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == 'B') {
                    if(i+1 < n && arr[i+1][j] == '.') {
                        arr[i+1][j] = '#';
                    } else if(i+1 < n && arr[i+1][j] == 'G') {
                        allBlocked = false;
                    }
                    if(i-1 >= 0 && arr[i-1][j] == '.') {
                        arr[i-1][j] = '#';
                    } else if(i-1 >= 0 && arr[i-1][j] == 'G') {
                        allBlocked = false;
                    }
                    if(j+1 < m && arr[i][j+1] == '.') {
                        arr[i][j+1] = '#';
                    } else if(j+1 < m && arr[i][j+1] == 'G') {
                        allBlocked = false;
                    }
                    if(j-1 >= 0 && arr[i][j-1] == '.') {
                        arr[i][j-1] = '#';
                    } else if(j-1 >= 0 && arr[i][j-1] == 'G') {
                        allBlocked = false;
                    }
                }
            }

        if(!allBlocked) {
            cout << "No\n";
            continue;
        }

        bool vis[51][51];
        memset(vis, false, sizeof vis);
        int gsfound = 0;
        queue<pair<int, int>> q;
        q.push({n-1, m-1});
        while(!q.empty()) {
            pair<int, int> itm = q.front();
            int i = itm.first;
            int j = itm.second;
            q.pop();
            if(vis[i][j])
                continue;
            vis[i][j] = true;
            if(arr[i][j] == 'G') {
                gsfound ++;
            } else if(arr[i][j] == '#')
                continue;
            if(i+1 < n && arr[i+1][j] != '#' && !vis[i+1][j]) {
                q.push({i+1, j});
            }
            if(i-1 >= 0 && arr[i-1][j] != '#' && !vis[i-1][j]) {
                q.push({i-1, j});
            }
            if(j+1 < m && arr[i][j+1] != '#' && !vis[i][j+1]) {
                q.push({i, j+1});
            }
            if(j-1 >= 0 && arr[i][j-1] != '#' && !vis[i][j-1]) {
                q.push({i, j-1});
            }
        }
        
        cout << (gsfound == nmgood ? "Yes\n" : "No\n");
    }
    
    return 0;
}
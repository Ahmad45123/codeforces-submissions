#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<char>> arr;
bool vis[51][51];

int countGs(int i, int j, int n, int m) {
    if(vis[i][j])
        return 0;
    if(arr[i][j] == '#')
        return 0;
    vis[i][j] = true;

    int cnt = (arr[i][j] == 'G' ? 1 : 0);
    if(i+1 <= n)
        cnt += countGs(i+1, j, n, m);
    if(i-1 >= 0)
        cnt += countGs(i-1, j, n, m);
    if(j+1 <= m)
        cnt += countGs(i, j+1, n, m);
    if(j-1 >= 0)
        cnt += countGs(i, j-1, n, m);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        arr = vector<vector<char>>(n, vector<char>(m));
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

        memset(vis, false, sizeof vis);
        int gsfound = countGs(n-1, m-1, n-1, m-1);
        
        cout << (gsfound == nmgood ? "Yes\n" : "No\n");
    }
    
    return 0;
}
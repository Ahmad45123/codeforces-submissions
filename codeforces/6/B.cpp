#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m; 
char c;
char arr[101][101];
bool vis[101][101];

void markAsVis(int i, int j, char k) {
    if(arr[i][j] != k)
        return;
    if(vis[i][j])
        return;
    vis[i][j] = true;

    if(i+1 < n)
        markAsVis(i+1, j, k);
    if(j+1 < m)
        markAsVis(i, j+1, k);
    if(i-1 >= 0)
        markAsVis(i-1, j, k);
    if(j-1 >= 0)
        markAsVis(i, j-1, k);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> m >> c;
    memset(vis, false, sizeof vis);
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == c)
                q.push({i, j});
        }
    
    int ans = 0;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if(cur.first+1 < n && arr[cur.first+1][cur.second] != '.' && arr[cur.first+1][cur.second] != c && !vis[cur.first+1][cur.second]) {
            ans ++;
            markAsVis(cur.first+1, cur.second, arr[cur.first+1][cur.second]);
        }
        if(cur.second+1 < m && arr[cur.first][cur.second+1] != '.' && arr[cur.first][cur.second+1] != c && !vis[cur.first][cur.second+1]) {
            ans ++;
            markAsVis(cur.first, cur.second+1, arr[cur.first][cur.second+1]);
        }
        if(cur.first-1 >= 0 && arr[cur.first-1][cur.second] != '.' && arr[cur.first-1][cur.second] != c && !vis[cur.first-1][cur.second]) {
            ans ++;
            markAsVis(cur.first-1, cur.second, arr[cur.first-1][cur.second]);
        }
        if(cur.second-1 >= 0 && arr[cur.first][cur.second-1] != '.' && arr[cur.first][cur.second-1] != c && !vis[cur.first][cur.second-1]) {
            ans ++;
            markAsVis(cur.first, cur.second-1, arr[cur.first][cur.second-1]);
        }
    }
    
    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int n;
vector<int> costs;
vector<int> rooms;

map<int, bool> vis;

void solve(int cur, int bs, int &mn) {
    
    if(cur == bs) {
        return;
    }

    mn = min(mn, costs[cur]);
    return solve(rooms[cur], bs, mn);
}

int vid = 0;
int vis2[200002];
int reach(int cur) {
    if(vis[cur])
        return cur;
    vis[cur] = true;
    vis2[cur] = vid;
    reach(rooms[cur]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    costs = vector<int>(n+1);
    rooms = vector<int>(n+1);
    for(int i = 1; i <= n; i++)
        cin >> costs[i];
    for(int i = 1; i <= n; i++)
        cin >> rooms[i];
    memset(vis2, 0, sizeof vis2);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        vid++;
        int c = reach(i);
        if(vis2[c] == vid) {
            int t = costs[c];
            solve(rooms[c], c, t);
            ans += t;
        }
    }

    cout << ans;

    return 0;
}
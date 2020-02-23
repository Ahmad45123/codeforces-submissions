#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x, y, i, j;
map<int, vector<pair<int, int>>> Allowed;

int solve() {
    queue<pair<int, int>> q;
    q.push({x, y});
    unordered_map<string, bool> vis;
    bool good = false;
    int curDist = 0;
    while(!good && !q.empty()) {
        int sz = q.size();
        while(sz--) {
            pair<int, int> cur = q.front();
            q.pop();
            if(vis[to_string(cur.first) + "-" + to_string(cur.second)])
                continue;
            vis[to_string(cur.first) + "-" + to_string(cur.second)] = true;

            if(cur.first == i && cur.second == j) {
                good = true;
                break;
            }

            map<int, vector<pair<int, int>>>::iterator itter = Allowed.find(cur.first);
            if(itter == Allowed.end())
                continue;
            bool allowed = false;
            for(int i = 0; i < Allowed[cur.first].size(); i++) {
                if(cur.second >= Allowed[cur.first][i].first && cur.second <= Allowed[cur.first][i].second) {
                    allowed = true;
                    break;
                }
            }
            if(!allowed)
                continue;
            
            pair<int, int> toCheck[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
            for(int i = 0; i < 8; i++) {
                if(cur.first+toCheck[i].first >= 1 && cur.first+toCheck[i].first <= 10e9 && cur.second+toCheck[i].second >= 1 && cur.second+toCheck[i].second <= 10e9) {
                    q.push({cur.first+toCheck[i].first, cur.second+toCheck[i].second});
                }
            }
        }
        curDist ++;
    }

    if(good)
        return curDist-1;
    else
        return -1;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> x >> y >> i >> j >> n;
    for(int i = 0 ; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        Allowed[r].push_back({a, b});
    }

    cout << solve() << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> graph[101];

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int steps = 0;
    while(true) {
        vector<int> toRemove;
        for(int i = 1; i <= n; i++) {
            if(graph[i].size() == 1)
                toRemove.push_back(i);
        }
        if(toRemove.size() == 0)
            break;
        for(int i = 0; i < toRemove.size(); i++) {
            int x = toRemove[i];
            for(int j = 0; j < graph[graph[x][0]].size(); j++) {
                int y = graph[graph[x][0]][j];
                if(y == x)
                {
                    graph[graph[x][0]].erase(graph[graph[x][0]].begin() + j);
                    break;
                }
            }
            graph[x] = vector<int>();
        }
        steps++;
    }
 
    cout << steps << "\n";

    return 0;
}
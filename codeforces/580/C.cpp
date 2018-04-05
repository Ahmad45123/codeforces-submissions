#include <bits/stdc++.h>

using namespace std;
#define ll long long int

vector<int> graph[1000000];

int main()
{
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<int> hasCat(n+1);
    for(int i = 1; i <= n; i++)
        cin >> hasCat[i];
    
    for(int i = 0; i < n-1; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //We start at 1, going forward until we find a vertex with no children, +1 res.
    int result = 0;
    map<int, bool> vis;
    queue<int> q;
    q.push(1);
    vis[1] = true;
    vector<int> previousCats(1000000);
    previousCats[1] = hasCat[1];

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        bool good = true;
        for(int i = 0; i < graph[cur].size(); i++)
        {
            if(!vis[graph[cur][i]]) {
                vis[graph[cur][i]] = true;
                good = false;
                if(hasCat[graph[cur][i]])
                {
                    previousCats[graph[cur][i]] = previousCats[cur]+1;
                    if(previousCats[graph[cur][i]] > m)
                        continue;
                }
                else
                    previousCats[graph[cur][i]] = 0;

                q.push(graph[cur][i]);
            }
        }

        if(good && cur != 1)
            result++;
    }

    cout << result;

    int xyz; cin >> xyz; return 0;
}
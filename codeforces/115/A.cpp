#include <bits/stdc++.h>

using namespace std;
#define ll long long int

vector<int> graph[3000];
int levels [3000];

int markAllSubStaff(int i)
{
    queue<int> q;
    map<int, bool> vis;
    vis[i] = true;
    levels[i] = 1;
    q.push(i);
    int maxLevel = 1;
    while(!q.empty())
    {
        int o = q.front();
        q.pop();

        for(int i = 0; i < graph[o].size(); i++)
        {
            if(!vis[graph[o][i]])
            {
                vis[graph[o][i]] = true;
                levels[graph[o][i]] = levels[o]+1;
                maxLevel = max(maxLevel, levels[graph[o][i]]);
                q.push(graph[o][i]);
            }
        }
    }

    return maxLevel;
}

int main()
{
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        if(x != -1)
        {
            graph[x].push_back(i);
        }
    }

    int ngroups = 0;
    for(int i = 1; i <= n; i++)
    {
        ngroups = max(ngroups, markAllSubStaff(i));
    }

    cout << ngroups;

    int xyz; cin >> xyz; return 0;
}
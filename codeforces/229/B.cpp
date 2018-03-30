#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<pair<int, int>> graph[100001];
vector<int> busyTimes[100001];

int main()
{
    int n, m; cin >> n >> m;
    while(m--)
    {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    //TODO: get busy times.
    for(int i = 1; i <= n; i++)
    {
        int c; cin >> c;
        for(int j = 0; j < c; j++)
        {
            int v; cin >> v;
            busyTimes[i].push_back(v);
        }
    }

    //basic dijikstra
    map<int, int> dists;
    map<int, bool> vis;
    multiset<pair<int, int>> q;
    
    dists[1] = 0;
    q.insert(make_pair(0, 1));
    for(int i = 2; i <= n; i++)
    {
        dists[i] = INT_MAX;
    }

    while(!q.empty())
    {
        pair<int, int> cur = *q.begin();
        q.erase(q.begin());
        int curNode = cur.second;

        if(curNode == n)
            break;

        if(vis[curNode])
            continue;

        vis[curNode] = true;

        //add delay
        for(int i = 0; i < busyTimes[curNode].size(); i++)
        {
            if(busyTimes[curNode][i] == dists[curNode])
                dists[curNode]++;
            else if(busyTimes[curNode][i] > dists[curNode])
                break;
        }

        for(int i = 0; i < graph[curNode].size(); i++)
        {
            int weight = graph[curNode][i].second;
            int tarNode = graph[curNode][i].first;
            int newDist = dists[curNode] + weight;

            if(dists[tarNode] > newDist)
            {
                dists[tarNode] = newDist;
                q.insert(make_pair(dists[tarNode], tarNode));
            }
        }
    }

    if(dists[n] == INT_MAX)
        dists[n] = -1;

    cout << dists[n];

    int xyz; cin >> xyz; return 0;
}
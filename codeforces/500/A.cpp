#include <bits/stdc++.h>

using namespace std;
#define ll long long int

vector<int> graph[100000];

int main()
{
    ios::sync_with_stdio(false);
    
    int n, t; cin >> n >> t;
    for(int i = 1; i <= n-1; i++)
    {
        int ai; cin >> ai;
        graph[i].push_back(i + ai);
    }

    //BFS on the graph to reach the dest.
    bool reached = false;
    vector<bool> visited(100000);
    queue<int> toVisit;
    toVisit.push(1);
    while(!toVisit.empty())
    {
        int cur = toVisit.front();
        toVisit.pop();

        if(reached)
            break;

        for(int i = 0; i < graph[cur].size(); i++)
        {
            int x = graph[cur][i];
            if(!visited[x])
            {
                visited[x] = true;
                if(x == t)
                {
                    reached = true;
                    break;
                }
                toVisit.push(x);
            }
        }
    }

    if(reached)
        cout << "YES";
    else
        cout << "NO";

    int xyz; cin >> xyz; return 0;
}
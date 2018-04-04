#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;

    queue<pair<int, int>> toDo;
    map<int, bool> vis;
    toDo.push(make_pair(n, 0));

    int minSteps = INT_MAX;
    while(!toDo.empty())
    {
        pair<int, int> curNumber = toDo.front();
        toDo.pop();

        if(vis[curNumber.first])
            continue;
        vis[curNumber.first] = true;

        if(curNumber.first == m)
            minSteps = min(minSteps, curNumber.second);
        else if(curNumber.first > m) {
            //Its bigger, we only need to subtract.
            toDo.push(make_pair(curNumber.first-1, curNumber.second+1));
        }
        else if(curNumber.first == 0)
            continue;
        else {
            //We add both.
            toDo.push(make_pair(curNumber.first-1, curNumber.second+1));
            toDo.push(make_pair(curNumber.first*2, curNumber.second+1));
        }
    }

    cout << minSteps;

    int xyz; cin >> xyz; return 0;
}
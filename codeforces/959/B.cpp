#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);

    int n, k, m; cin >> n >> k >> m;
    vector<string> words(n);
    for(int i = 0; i < n; i++)
        cin >> words[i];

    map<string, int> costs;
    for(int i = 0; i < n; i++)
    {
        int c; cin >> c;
        costs[words[i]] = c;
    }

    //Start replacing costs.
    while(k--)
    {
        int count; cin >> count;
        vector<int> group(count);
        int minCost = INT_MAX;
        for(int i = 0; i < count; i++)
        {
            int x; cin >> x;
            group[i] = x-1;
            minCost = min(minCost, costs[words[x-1]]);
        }

        //Set all to minimum
        for(int i = 0; i < count; i++)
        {
            costs[words[group[i]]] = minCost;
        }
    }

    //Now get sum.
    ll sum = 0;
    for(int i = 0; i < m; i++)
    {
        string word; cin >> word;
        sum += costs[word];
    }

    cout << sum;

    int xyz; cin >> xyz; return 0;
}
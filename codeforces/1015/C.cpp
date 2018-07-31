#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

bool comp(int a, int b) {
    return a > b;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<pair<int, int>> arr(n);
    vector<int> diffs(n);
    for(int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        arr[i] = {s,e};
        diffs[i] = s-e;
    }

    ll allSum = 0;
    for(int i = 0; i < n; i++)
        allSum += arr[i].first;

    if(allSum <= m) {
        cout << 0;
        return 0;
    }

    sort(diffs.begin(), diffs.end(), comp);
    int steps = 0;
    ll needed = allSum-m;
    for(int i = 0; i < diffs.size(); i++) {
        needed -= diffs[i];
        if(needed <= 0) {
            cout << i+1;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
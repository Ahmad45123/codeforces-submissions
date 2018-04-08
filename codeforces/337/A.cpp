#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<int> arr(m);
    for(int i = 0; i < m; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int best = INT_MAX;
    for(int k = 0; k <= m-n; k++)
        best = min(best, arr[k+n-1] - arr[k]);

    cout << best << endl;

    int xyz; cin >> xyz; return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    map<int, int> count;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        count[arr[i]]++;
        ans = max(ans, count[arr[i]]);
    }

    cout << ans << '\n';

    return 0;
}
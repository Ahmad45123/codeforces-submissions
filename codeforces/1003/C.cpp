#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    double ans = 0;

    for(int si = k; si <= n; si++) {
        double tans = 0;
        for(int t = 0; t < si; t++) {
            tans += arr[t];
        }
        tans /= si;
        ans = max(ans, tans);

        for(int i = si; i < n; i++) {
            tans *= si;
            tans -= arr[i-si];
            tans += arr[i];
            tans /= si;
            ans = max(ans, tans);
        }
    }

    cout << setprecision(15) << ans << '\n';
    return 0;
}
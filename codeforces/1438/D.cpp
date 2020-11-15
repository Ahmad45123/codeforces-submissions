#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    
    vector<pair<int, pair<int, int>>> ans;

    int expValue = -1;
    if(n % 2 == 0) {
        expValue = arr[n-1];
        n --;
    }

    for(int i = 0; i <= n-3; i += 2) {
        ans.push_back({i, {i+1, i+2}});
        arr[i] = arr[i]^arr[i+1]^arr[i+2];
        arr[i+1] = arr[i];
        arr[i+2] = arr[i];
    }

    for(int i = n-3; i >= 2; i -= 2) {
        ans.push_back({i, {i-1, i-2}});
        arr[i] = arr[i]^arr[i-1]^arr[i-2];
        arr[i-1] = arr[i];
        arr[i-2] = arr[i];
    }

    if(expValue == -1 || arr[0] == expValue) {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for(auto x : ans) {
            cout << x.first+1 << " " << x.second.first+1 << " " << x.second.second+1 << "\n";
        }
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n+1);
    arr[0] = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i+1];
    
    int tmp = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        tmp += arr[i]-arr[i+1];
        if(tmp < 0) {
            ans += -tmp;
            tmp = 0;
        }
    }

    cout << ans << "\n";

    return 0;
}
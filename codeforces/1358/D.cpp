#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getHugs(ll x) {
    return (x*(x+1))/2;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll n, x; cin >> n >> x;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(ll i = 0; i < n; i++) {
        arr.push_back(arr[i]);
    }

    ll ans = 0;
    ll curHugs = 0;
    ll curDays = 0;
    int j = 0;
    for(int i = 0; i < 2*n; i++) {
        curDays += arr[i];
        curHugs += getHugs(arr[i]);
        while(curDays > x) {
            int tmp = curDays-x;
            if(arr[j] <= tmp) {
                curDays -= arr[j];
                curHugs -= getHugs(arr[j]);
                j ++;
            } else {
                ans = max(ans, curHugs-getHugs(tmp));
                break;
            }
        }
        if(curDays == x) {
            ans = max(ans, curHugs);
        }
    }
    
    cout << ans << "\n";

    return 0;
}
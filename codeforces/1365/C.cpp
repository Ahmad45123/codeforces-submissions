#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> pos(n+1);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        pos[x] = i;
    }

    map<int, int> cnt;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        int oldPos = pos[x];
        if(oldPos >= i) {
            cnt[oldPos-i] ++;
        } else {
            cnt[n-i+oldPos] ++;
        }
    }

    int ans = 0;
    for(auto it = cnt.begin(); it != cnt.end(); it++) {
        ans = max(ans, it->second);
    }

    cout << ans << "\n";
    
    return 0;
}
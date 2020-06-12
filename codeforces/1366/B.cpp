#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, x, m; cin >> n >> x >> m;
        vector<pair<int, int>> good;
        int ans = 0;
        while(m--) {
            int l, r; cin >> l >> r;
            bool merged = false;
            for(int i = 0; i < good.size(); i++) {
                if(l <= good[i].first && r >= good[i].second) {
                    good[i].first = l;
                    good[i].second = r;
                    merged = true;
                    break;
                } else if(l <= good[i].first && r >= good[i].first && r <= good[i].second) {
                    good[i].first = l;
                    merged = true;
                    break;
                } else if(l >= good[i].first && r <= good[i].second) {
                    merged = true;
                    break;
                } else if(l >= good[i].first && l <= good[i].second && r >= good[i].second) {
                    good[i].second = r;
                    merged = true;
                    break;
                }
            }

            if(!merged && x >= l && x <= r)
                good.push_back({l, r});
        }

        for(int i = 0; i < good.size(); i++) {
            ans += good[i].second-good[i].first+1;
        }
        cout << (ans == 0 ? 1 : ans) << "\n";
    }
    
    return 0;
}
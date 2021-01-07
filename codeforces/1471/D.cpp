#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> maxPerfect(1e6+1, 1);
    for(int i = 2; i <= 1000; i++) {
        int sq = i*i;
        for(int j = sq; j <= 1e6; j += sq) {
            maxPerfect[j] = sq;
        }
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int, int> cnt;
        int ansZero = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            x = x/maxPerfect[x];
            cnt[x] ++;
            ansZero = max(ansZero, cnt[x]);
        }
        
        int ansOne = 0;
        for(auto it = cnt.begin(); it != cnt.end(); it ++) {
            if(it->first == 1) continue;
            if(it->second % 2 == 0) {
                cnt[1] += it->second;
                it->second = 0;
            } else {
                ansOne = max(ansOne, it->second);
            }
        }
        ansOne = max(ansOne, cnt[1]);
        
        int q; cin >> q;
        while(q--) {
            ll time; cin >> time;
            if(time == 0)
                cout << ansZero << "\n";
            else
                cout << ansOne << "\n";
        }
    }
    
    return 0;
}
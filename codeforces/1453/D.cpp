#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<ll> values;
    ll tmp = 2;
    while(tmp < 1e18) {
        values.push_back(tmp);
        tmp = (tmp+1)*2LL;
    }

    int t; cin >> t;
    while(t--) {
        ll k; cin >> k;
        if(k % 2 != 0) {
            cout << "-1\n";
            continue;
        }
        k -= 2;
        string ans = "1";
        while(k > 0) {
            auto val = lower_bound(values.begin(), values.end(), k);
            if(*val > k)
                val --;
            int pos = val-values.begin();
            for(int i = 0; i < pos; i++)
                ans += '0';
            ans += '1';
            k -= *val;
        }

        cout << ans.size() << "\n";
        for(char c : ans)
            cout << c << " ";
        cout << "\n";
    }

    return 0;
}
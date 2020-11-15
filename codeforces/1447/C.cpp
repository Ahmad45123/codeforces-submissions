#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll W; cin >> W;

        vector<pair<ll, ll>> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i].second;
            arr[i].first = i+1;
        }
        
        ll mn = ceil(W*1.0/2.0);

        sort(arr.begin(), arr.end(), comp);

        vector<int> ans;

        ll sum = 0;
        bool good = false;
        for(int i = 0; i < n; i++) {
            if(sum + arr[i].second <= W) {
                sum += arr[i].second;
                ans.push_back(arr[i].first);
            }

            if(sum >= mn) {
                good = true;
                break;
            }
        }

        if(good) {
            cout << ans.size() << "\n";
            for(int x : ans)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}
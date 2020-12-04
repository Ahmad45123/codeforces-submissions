#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
bool comp2(pair<int, int> a, pair<int, int> b) { 
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<pair<int, int>>> locs(10, vector<pair<int, int>>());
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                char c; cin >> c;
                locs[c-'0'].push_back({i, j});
            }


        for(int cur = 0; cur < 10; cur ++) {
            if(locs[cur].size() < 2) {
                cout << "0 ";
                continue;
            }

            int sz = locs[cur].size();
            int val = 0;

            sort(locs[cur].begin(), locs[cur].end(), comp);
            
            for(int i = 0; i < locs[cur].size(); i ++) {
                pair<int, int> mnX = locs[cur][i];
                pair<int, int> mxX = locs[cur][0];

                val = max(val, abs(mnX.second - mxX.second) * max(mnX.first, n-mnX.first-1));
                val = max(val, abs(mnX.second - mxX.second) * max(mxX.first, n-mxX.first-1));
                val = max(val, abs(mnX.first - mxX.first) * max(mnX.second, n-mnX.second-1));
                val = max(val, abs(mnX.first - mxX.first) * max(mxX.second, n-mxX.second-1));

                mxX = locs[cur][sz-1];

                val = max(val, abs(mnX.second - mxX.second) * max(mnX.first, n-mnX.first-1));
                val = max(val, abs(mnX.second - mxX.second) * max(mxX.first, n-mxX.first-1));
                val = max(val, abs(mnX.first - mxX.first) * max(mnX.second, n-mnX.second-1));
                val = max(val, abs(mnX.first - mxX.first) * max(mxX.second, n-mxX.second-1));
            }

            sort(locs[cur].begin(), locs[cur].end(), comp2);
            for(int i = 0; i < locs[cur].size(); i ++) {
                pair<int, int> mnX = locs[cur][i];
                pair<int, int> mxX = locs[cur][0];

                val = max(val, abs(mnX.second - mxX.second) * max(mnX.first, n-mnX.first-1));
                val = max(val, abs(mnX.second - mxX.second) * max(mxX.first, n-mxX.first-1));
                val = max(val, abs(mnX.first - mxX.first) * max(mnX.second, n-mnX.second-1));
                val = max(val, abs(mnX.first - mxX.first) * max(mxX.second, n-mxX.second-1));

                mxX = locs[cur][sz-1];

                val = max(val, abs(mnX.second - mxX.second) * max(mnX.first, n-mnX.first-1));
                val = max(val, abs(mnX.second - mxX.second) * max(mxX.first, n-mxX.first-1));
                val = max(val, abs(mnX.first - mxX.first) * max(mnX.second, n-mnX.second-1));
                val = max(val, abs(mnX.first - mxX.first) * max(mxX.second, n-mxX.second-1));
            }
            

            cout << val << " ";
        }

        cout << "\n";
    }
    
    return 0;
}
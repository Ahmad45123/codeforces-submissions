#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<pair<int, int>> packs;
        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            packs.push_back({x, y});
        }

        sort(packs.begin(), packs.end(), compare);
        string ans = "";

        int prevx = 0, prevy = 0;

        for(int i = 0; i < n; i++) {
            int neededR = packs[i].first - prevx;
            while(neededR--)
                ans += "R";
            int neededU = packs[i].second - prevy;
            if(neededU < 0) {
                ans = "NO";
                break;
            }
            while(neededU--)
                ans += "U";

            prevx = packs[i].first;
            prevy = packs[i].second;
        }

        if(ans == "NO")
            cout << "NO\n";
        else {
            cout << "YES\n" << ans << "\n";
        }
    }
    
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m, x; cin >> n >> m >> x;
    vector<pair<int, int>> bad;
    unordered_map<char, double> dists;
    unordered_map<char, vector<pair<int, int>>> pos;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if(c == 'S')
                bad.push_back({i, j});
            else {
                pos[c].push_back({i, j});
            }
        }

    for(unordered_map<char, vector<pair<int, int>>>::iterator itter = pos.begin(); itter != pos.end(); itter++) {
        double lowestDist = 1e9;
        for(int i = 0; i < bad.size(); i++) {
            for(int j = 0; j < itter->second.size(); j++) {
                pair<int, int> charpos = itter->second[j];
                double dist = sqrt(pow(bad[i].first-charpos.first, 2)+pow(bad[i].second-charpos.second, 2));
                lowestDist = min(lowestDist, dist);
            }
        }
        dists[itter->first] = lowestDist;
    }
    
    int q; cin >> q;
    string input; cin >> input;

    int ans = 0;

    for(int i = 0; i < q; i++) {
        if(isupper(input[i])) {
            char low = tolower(input[i]);
            if(pos.find(low) == pos.end()) {
                cout << -1 << "\n";
                return 0;
            } else {
                double lowestDist = dists[low];
                if(lowestDist == 1e9)
                {
                    cout << -1 << "\n";
                    return 0;
                }
                else if(lowestDist > x)
                    ans ++;
            }
        } else {
            if(pos.find(input[i]) == pos.end())
            {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
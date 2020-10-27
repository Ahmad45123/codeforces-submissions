#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<string> values;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 4; j++) {
            string t(j, '0'+i);
            values.push_back(t);
        }
    }

    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        string toFind = to_string(x);
        int cnt = 0;
        for(int i = 0; i < values.size(); i++) {
            cnt += values[i].size();
            if(values[i] == toFind)
                break;
        }
        cout << cnt << "\n";
    }
    
    return 0;
}
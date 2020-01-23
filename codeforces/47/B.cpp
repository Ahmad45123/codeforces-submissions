#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    map<char, int> mp;

    for(int i = 0; i < 3; i++) {
        string s; cin >> s;
        if(s[1] == '>') {
            mp[s[0]] ++;
            mp[s[2]] --;
        } else {
            mp[s[0]] --;
            mp[s[2]] ++;
        }
    }

    if(mp['A'] == mp['B'] || mp['A']  == mp['C'] || mp['B'] == mp['C'])
        cout << "Impossible\n";
    else {
        vector<pair<int, char>> temp;
        temp.push_back({mp['A'], 'A'});
        temp.push_back({mp['B'], 'B'});
        temp.push_back({mp['C'], 'C'});
        sort(temp.begin(), temp.end());
        cout << temp[0].second << temp[1].second << temp[2].second << "\n";
    }
    
    return 0;
}
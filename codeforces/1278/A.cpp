#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isGood(int i, string hash, string target) {
    map<char, int> mp;
    for(int j = 0; j < target.size(); j++) {
        mp[target[j]] ++;
    }

    for(int j = i; j < hash.size(); j++) {
        _Rb_tree_iterator<pair<const char, int>> x = mp.find(hash[j]);
        if(x == mp.end()) {
            break;
        }
        if(x->second == 0) {
            break;
        }
        x->second --;
    }

    for(int j = 0; j < target.size(); j++) {
        if(mp[target[j]] != 0)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        string s, hash; cin >> s >> hash;
        bool good = false;
        for(int i = 0; i < hash.size(); i++) {
            if(isGood(i, hash, s)) {
                good = true;
                break;
            }
        }
        cout << (good ? "YES\n" : "NO\n");
    }
    
    return 0;
}
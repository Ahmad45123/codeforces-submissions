#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    int fours = 0, twos = 0, sixes = 0, eights = 0;
    vector<int> mp(100001);
    for(int i = 0; i < n; i++) {
        int x ; cin >> x;
        eights -= mp[x] / 8;
        sixes -= mp[x] / 6;
        fours -= mp[x] / 4;
        twos -= mp[x] / 2;
        mp[x] ++;
        eights += mp[x] / 8;
        sixes += mp[x] / 6;
        fours += mp[x] / 4;
        twos += mp[x] / 2;
    }


    int q; cin >> q;
    while(q--) {
        char o; int v; cin >> o >> v;
        eights -= mp[v] / 8;
        sixes -= mp[v] / 6;
        fours -= mp[v] / 4;
        twos -= mp[v] / 2;
            
        if(o == '+') {
            mp[v] ++;
        }
        else if(o == '-') {
            mp[v] --;
        }

        eights += mp[v] / 8;
        sixes += mp[v] / 6;
        fours += mp[v] / 4;
        twos += mp[v] / 2;

        bool good = false;
        if(eights >= 1) {
            good = true;
        } else if(sixes >= 1 && twos >= 5) {
            good = true;
        } else if(fours >= 2) {
            good = true;
        } else if(fours >= 1 && twos >= 4) {
            good = true;
        }

        cout << (good ? "YES\n" : "NO\n");
    }
    
    return 0;
}
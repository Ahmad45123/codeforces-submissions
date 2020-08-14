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
        fours -= mp[x] / 4;
        twos -= mp[x] / 2;
        mp[x] ++;
        fours += mp[x] / 4;
        twos += mp[x] / 2;
    }


    int q; cin >> q;
    while(q--) {
        char o; int v; cin >> o >> v;

        fours -= mp[v] / 4;
        twos -= mp[v] / 2;
            
        if(o == '+') {
            mp[v] ++;
        }
        else if(o == '-') {
            mp[v] --;
        }

        fours += mp[v] / 4;
        twos += mp[v] / 2;

        cout << (fours >= 1 && twos >= 4 ? "YES\n" : "NO\n");
    }
    
    return 0;
}
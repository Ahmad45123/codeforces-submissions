#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
vector<int> arr;

string trySolve() {
    string ans(arr.size(), '?');
    map<char, int> cnt;
    for(char c : s)
        cnt[c] ++;
    auto j = cnt.rbegin();
    while(true) {
        vector<int> toChange;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0 && ans[i] == '?') {
                toChange.push_back(i);
            }
        }
        if(toChange.size() == 0)
            break;
        while(j->second < toChange.size())
            j++;
        for(int x : toChange) {
            ans[x] = j->first;
            for(int i = 0; i < arr.size(); i++) {
                if(arr[i] > 0) {
                    arr[i] -= abs(x-i);
                }
            }
        }
        j++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q; cin >> q;
    while(q--) {
        cin >> s;
        int m; cin >> m;
        arr.resize(m);
        for(int &x : arr)
            cin >> x;
        string ans = trySolve();
        cout << ans << "\n";
    }
    
    return 0;
}
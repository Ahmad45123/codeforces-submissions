#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isDistinct(int i) {
    string s = to_string(i);
    map<char, bool> used;
    for(int j = 0; j < s.size(); j++) {
        if(used[s[j]])
            return false;
        used[s[j]] = true;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int a, b; cin >> a >> b;
    for(int i = a; i <= b; i++) {
        if(isDistinct(i)) {
            cout << i << "\n";
            return 0;
        }
    }
    
    cout << -1 << "\n";
    return 0;
}
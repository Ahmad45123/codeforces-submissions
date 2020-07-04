#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll k; cin >> k;
    vector<int> counts(10, 1);

    ll tmp = 1;
    int i = 0;
    while(tmp < k) {
        tmp /= counts[i];
        counts[i] += 1;
        tmp *= counts[i];
        i++;
        if(i >= 10)
            i = 0;
    }

    string s = "codeforces";
    for(int i = 0; i < counts.size(); i++) {
        for(int j = 0; j < counts[i]; j++) {
            cout << s[i];
        }
    }
    cout << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n; int k;
    cin >> n >> k;
    string s; cin >> s;

    sort(s.begin(), s.end());
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]+1 || s[i] == s[i-1])
        {
            s.erase(s.begin()+i);
            n--;
            i--;
        }
    }

    if(k <= n) {
        int ans = 0;
        for(int i = 0; i < k; i++) {
            ans += s[i]-'a'+1;
        }
        cout << ans;
    }
    else
        cout << -1;

    return 0;
}
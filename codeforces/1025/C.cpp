#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    s += s;
    int n = s.size();


    int cur = 1;
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1])
        {
            ans = max(ans, cur);
            cur = 0;
        }
        cur ++;
    }
    ans = max(ans, cur);

    cout << min(ans, n/2);
    return 0;
}
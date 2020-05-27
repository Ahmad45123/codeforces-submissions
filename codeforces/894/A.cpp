#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'Q') {
            int As = 0;
            for(int j = i+1; j < n; j++) {
                if(s[j] == 'A')
                    As ++;
                else if(s[j] == 'Q') {
                    ans += As;
                }
            }
        }
    }

    cout << ans << "\n";
    
    return 0;
}
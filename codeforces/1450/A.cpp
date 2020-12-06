#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> cnt(27);

        string a = "trygub";
        for(int i = 0; i < n; i++)
            cnt[s[i]-'a'] ++;
        
        string ans = "";
        for(char c = 'a'; c <= 'z'; c++) {
            while(cnt[c-'a']--)
                ans += c;
        }

        cout << ans << "\n";
    }
    
    return 0;
}
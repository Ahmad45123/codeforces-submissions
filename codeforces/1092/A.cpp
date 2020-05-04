#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        int freq = n/k;
        string ans = "";
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < freq; j++)
                ans += 'a'+i;
        }
        while(ans.size() < n) {
            ans += 'a';
        }
        cout << ans << "\n";
    }
    
    
    return 0;
}
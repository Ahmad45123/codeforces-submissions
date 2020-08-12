#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int eights = ceil(n*1.0/4);
        string ans = "";
        for(int i = 0; i < n-eights; i++) 
            ans += '9';
        for(int i = 0; i < eights; i++)
            ans += '8';
        cout << ans << "\n";
    }
    
    return 0;
}
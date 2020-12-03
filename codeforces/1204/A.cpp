#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string s; cin >> s;
    int cntOnes = 0;
    for(char c : s)
        if(c == '1') cntOnes ++;
    
    int ans = (int)ceil(s.size()*1.0/2.0);
    if(cntOnes <= 1 && s.size() % 2 != 0) ans --;
    cout << ans << "\n";
    
    return 0;
}
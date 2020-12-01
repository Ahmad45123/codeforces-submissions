#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        int sum = 0;
        int ans = 0;
        for(int i = 1; sum < x; i++)
            sum += i, ans ++;
        if(sum-x == 1)
            ans ++;
        cout << ans << "\n";
    }
    
    return 0;
}
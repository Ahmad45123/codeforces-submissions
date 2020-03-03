#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> rem;
    int ans = 0;
    while(n--) {
        int hi; cin >> hi;
        int r = hi%(a+b);
        if(r == 0) {
            rem.push_back(ceil((a+b)*1.0/a)-1);
        } else if(r <= a) {
            ans ++;
        } else {
            rem.push_back(ceil(r*1.0/a)-1);
        }
    }
    
    sort(rem.begin(), rem.end());

    int curK = 0;
    for(int i = 0; i < rem.size(); i++) {
        if(curK+rem[i] > k)
            break;
        curK += rem[i];
        ans ++;
    }

    cout << ans << "\n";

    return 0;
}
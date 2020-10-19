#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    
    ll ans = 0;

    int cntNeg = 0;
    int cntZero = 0;
    for(int &x : arr) {
        cin >> x;
        if(x < 0) {
            cntNeg ++;
            ans += -1-x;
        } else if(x == 0)
            cntZero ++;
        else {
            ans += x-1;
        }
    }
    
    if(cntNeg % 2 != 0) {
        if(cntZero > 0) {
            cntZero --;
            ans += 1;
        } else {
            ans += 2;
        }
    }

    cout << ans+cntZero << "\n";
    
    return 0;
}
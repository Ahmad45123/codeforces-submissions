#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m, k; cin >> n >> m >> k;
    vector<int> arrA(n);
    vector<int> arrB(m);
    for(int &i : arrA)
        cin >> i;
    for(int &i : arrB)
        cin >> i;
    
    map<int, int> onesA;
    map<int, int> onesB;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        if(arrA[i] == 1)
            cur ++;
        else {
            for(int j = 1; j <= cur; j++) {
                onesA[j] += cur-j+1;
            }
            cur = 0;
        }
    }
    if(cur != 0)
        for(int j = 1; j <= cur; j++) {
            onesA[j] += cur-j+1;
        }
    cur = 0;
    for(int i = 0; i < m; i++) {
        if(arrB[i] == 1)
            cur ++;
        else {
            for(int j = 1; j <= cur; j++) {
                onesB[j] += cur-j+1;
            }
            cur = 0;
        }
    }
    if(cur != 0)
        for(int j = 1; j <= cur; j++) {
            onesB[j] += cur-j+1;
        }

    ll ans = 0;

    for(int x = 1; x <= n; x++) {
        if(k % x == 0) {
            int y = k / x;
            ans += onesA[x]*onesB[y];
        }
    }

    cout << ans << "\n";

    return 0;
}
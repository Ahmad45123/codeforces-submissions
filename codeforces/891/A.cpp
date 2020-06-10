#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    int nOnes = 0;
    for(int &x : arr) {
        cin >> x;
        if(x == 1)
            nOnes ++;
    }

    if(nOnes > 0) {
        cout << n-nOnes << "\n";
        return 0;
    }
    
    int steps = 1e9;

    for(int i = 0; i < n; i++) {
        int gcd = arr[i];
        for(int j = i+1; j < n; j++) {
            gcd = __gcd(gcd, arr[j]);
            if(gcd == 1) {
                steps = min(steps, j-i);
            }
        }
    }

    if(steps == 1e9)
        cout << -1 << "\n";
    else
        cout << steps+n-1 << "\n";
    
    return 0;
}
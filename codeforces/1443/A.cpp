#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> ans;
        int cnt = 0;
        for(int i = 2*n; i <= 4*n; i++) {                

            bool fnd = false;
            for(int x : ans) {
                if(__gcd(x, i) == 1 || x % i == 0 || i % x == 0) {
                    fnd = true;
                }
            }
            if(fnd) continue;
            ans.push_back(i);
            cnt ++;
            if(cnt >= n)
                break;
        }
        for(int x : ans)
            cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}
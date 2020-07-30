#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n, m; cin >> n >> m;
        vector<int> A(m+1);
        vector<ll> sortedA(m+1);
        vector<int> B(m+1);
        for(int i = 1; i <= m; i++) {
            cin >> A[i] >> B[i];
            sortedA[i] = A[i];
        }

        sort(sortedA.begin(), sortedA.end());

        vector<ll> sumA = sortedA;
        for(int i = 1; i <= m; i++) {
            sumA[i] += sumA[i-1];
        }

        ll ans = 0;

        for(int i = 1; i <= m; i++) {
            ll sum = 0;
            int idx = upper_bound(sortedA.begin(), sortedA.end(), B[i])-sortedA.begin();
            if(A[i] <= B[i]) {
                sum += A[i];
            }
            int cnt = m-idx+1;
            if(cnt >= n) {
                idx += cnt-n;
                cnt = m-idx+1;
            }
            sum += sumA[m]-sumA[idx-1];
            sum += B[i]*(n-cnt-(A[i] <= B[i] ? 1 : 0));
            ans = max(ans, sum);
        }

        cout << ans << "\n";
    }
    
    return 0;
}
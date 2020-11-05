    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;

    int main()
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
        int t; cin >> t;
        while(t--) {
            ll p, q; cin >> p >> q;
            if(q > p || p % q != 0) {
                cout << p << "\n";
            } else { // q >= p AND p % q == 0
                vector<int> primes;
                ll oldQ = q;

                if(q % 2 == 0)
                    primes.push_back(2);
                while(q % 2 == 0)
                    q /= 2;
                for(int i = 3; i <= sqrt(q); i += 2) {
                    if(q % i == 0)
                        primes.push_back(i);
                    while(q % i == 0) q /= i;
                }
                if(q > 2)
                    primes.push_back(q);
                
                ll ans = 0;
                for(int x : primes) {
                    ll tmp = p;
                    while(tmp % oldQ == 0) {
                        tmp /= x;
                    }
                    ans = max(ans, tmp);
                }
                cout << ans << "\n";
            }
        }
        
        return 0;
    }
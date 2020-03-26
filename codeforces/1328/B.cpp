#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        
        ll first = 0, second = 0;
        ll a = floorl(sqrtl(2.0L*k) + 1.0L/2.0L);
        first = n-a;
        ll b = k-((a*(a-1))/2);
        second = n-b+1;

        string tmp = "";
        for(int i = 1; i <= n; i++)
        {
            if(i == first || i == second)
                tmp += 'b';
            else
                tmp += 'a';
        }
        cout << tmp << "\n";
    }
    
    return 0;
}
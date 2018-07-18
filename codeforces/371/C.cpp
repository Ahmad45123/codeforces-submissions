#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

ll B = 0, S = 0, C = 0;
ll curB, curS, curC;
ll priceB, priceS, priceC;
ll money;


ll solve(ll x)
{
    ll breadCount = max(0LL, B*x-curB);
    ll sausageCount = max(0LL, S*x-curS);
    ll cheeseCount = max(0LL, C*x-curC);
    return breadCount*priceB + sausageCount*priceS + cheeseCount*priceC;
}

int main()
{
    
    string tmp; cin >> tmp;
    for(ll i = 0; i < tmp.size(); i++)
    {
        if(tmp[i] == 'S') S++;
        else if(tmp[i] == 'B') B++;
        else if(tmp[i] == 'C') C++;
    }
    cin >> curB >> curS >> curC;
    cin >> priceB >> priceS >> priceC;
    cin >> money;
    
    ll l = 0, r = 1e13;
    while(l <= r)
    {
        ll mid = (l+r)/2;
        ll t = solve(mid);
        if(t <= money) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }

    cout << l-1;

    return 0;
}
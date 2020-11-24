#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll, ll>> factorize(ll n) 
{ 
    vector<pair<ll, ll>> ans;
    
    int count = 0; 
  
    // count the number of times 2 divides  
    while (!(n % 2)) { 
        n >>= 1; // equivalent to n=n/2; 
        count++; 
    } 
  
    // if 2 divides it 
    if (count) 
        ans.push_back({2, count});
  
    // check for all the possible numbers that can  
    // divide it 
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
            ans.push_back({i, count});
    } 
  
    // if n at the end is a prime number. 
    if (n > 2) 
        ans.push_back({n, 1});
    
    return ans;
} 

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<pair<ll, ll>> arr = factorize(n);
        ll mxCnt = 0;
        ll mxValue = 0;
        for(auto x : arr) {
            if(x.second > mxCnt) {
                mxCnt = x.second;
                mxValue = x.first;
            }
        }

        ll mul = 1;
        for(auto x : arr) {
            if(x.first != mxValue) {
                while(x.second --)
                    mul *= x.first;
            }
        }

        cout << mxCnt << "\n"; mxCnt --;
        while(mxCnt --) {
            cout << mxValue << " ";
        }
        cout << mul*mxValue << "\n";
    }
    
    return 0;
}
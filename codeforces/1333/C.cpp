#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll n; cin >> n;
    vector<int> arr(n);
    for(int &x : arr)
        cin >> x;
    
    map<ll, int> prevSum; 
    ll res = 0; 
    ll currsum = 0; 
    int last = 0;
  
    for (int i = 0; i < n; i++) {          
        auto it = prevSum.find(currsum);
        if (it != prevSum.end()) { 
            int j = it->second+1-last;
            if(j > 0) {
                last = it->second+1;
                res += j*(n-i+1);
            } 
        }
          
        prevSum[currsum] = i;
        currsum += arr[i]; 
    } 
    auto it = prevSum.find(currsum);
    if (it != prevSum.end()) { 
        int j = it->second+1-last;
        if(j > 0) {
            res += j; 
        }
    }
    
    cout <<(n*(n+1)/2)-res << "\n";

    return 0;
}
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k; 
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    
    //First get the value.
    vector<int> sorted = arr;
    map<int, bool> bigValue;
    sort(sorted.begin(), sorted.end(), greater<int>());
    ll sum = 0;
    for(int i = 0; i < k; i++) {
        bigValue[sorted[i]] = true;
        sum += sorted[i];
    }

    ll count = 1;

    int lastBigValue = -1;
    for(int i = 0; i < n; i++) {
        if(bigValue[arr[i]] == true) {
            if(lastBigValue != -1) {
                int dist = i-lastBigValue;
                count *= dist%998244353;
                count %= 998244353;
            }
            lastBigValue = i;
        }
    }
    
    cout << sum << " " << count << "\n";

    return 0;
}
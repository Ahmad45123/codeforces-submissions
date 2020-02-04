#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    
    int curSum = 0;
    int minSum = 0;
    int pos = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i < k)
            curSum += arr[i];
    }
    minSum = curSum;

    for(int i = k; i < n; i++) {
        curSum += arr[i];
        curSum -= arr[i-k];
        if(curSum < minSum) {
            minSum = curSum;
            pos = i-k+1;
        }
    }
    
    cout << pos+1 << "\n";

    return 0;
}
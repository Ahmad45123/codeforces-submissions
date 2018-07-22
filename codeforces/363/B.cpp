#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    int curSum = 0;
    int smallSum = INT_MAX;
    int ans = 1;

    for(int i = 1; i <= k; i++)
        curSum += arr[i];
    smallSum = curSum;
    for(int i = k+1; i <= n; i++) {
        curSum -= arr[i-k];
        curSum += arr[i];
        if(curSum < smallSum) {
            smallSum = curSum;
            ans = i-k+1;
        }
    }

    cout << ans;
    return 0;
}
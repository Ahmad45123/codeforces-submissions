#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> ev(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] % 2 == 0)
            ev[i] = 1;
        else
            ev[i] = -1;
    }

    int curSum = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        curSum += ev[i];
        if(curSum == 0 && i+1 < n) {
            ans.push_back(abs(arr[i+1]-arr[i]));
        }
    }

    int a = 0;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] <= k) {
            k -= ans[i];
            a++;
        }
        else
            break;
    }

    cout << a;
    return 0;
}
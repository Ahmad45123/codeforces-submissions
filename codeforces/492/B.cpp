#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, l; cin >> n >> l;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    double ans = 0;

    for(int i = 0; i < n; i++) {
        double leftdist;
        if(i == 0) {
            leftdist = arr[0];
        } else {
            leftdist = (arr[i]-arr[i-1]) / 2.0;
        }
        double rightdist;
        if(i == n-1) {
            rightdist = l-arr[n-1];
        } else {
            rightdist = (arr[i+1]-arr[i]) / 2.0;
        }

        double total = max(leftdist, rightdist);
        ans = max(ans, total);
    }
    
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}
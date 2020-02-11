#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    bool sorted = true;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i > 0 && arr[i] < arr[i-1]) {
            sorted = false;
        }
    }

    if(sorted) {
        cout << "yes\n1 1\n";
        return 0;
    }
    
    int l = 0, r = 0;
    int ans = 0;
    int lastmx = 0;
    int lastmn = 0;
    bool wasIncrease = true;

    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i-1]) {
            if(wasIncrease) {
                l = i-1;
                r = i;
                lastmx = max(arr[i], arr[i-1]);
                lastmn = min(arr[i], arr[i-1]);
                wasIncrease = false;
            } else {
                r = i;
                lastmx = max(lastmx, arr[i]);
                lastmn = min(lastmn, arr[i]);
            }
        } else {
            if(wasIncrease == false) {
                if(arr[i] >= lastmx && (l-1 < 0 || lastmn >= arr[l-1])) {
                    ans ++;
                }
                wasIncrease = true;
            }
        }
    }

    if(!wasIncrease && (l-1 < 0 || lastmn >= arr[l-1]))
        ans ++;
    
    if(ans == 1) {
        cout << "yes\n" << l+1 << " " << r+1 << "\n";
    } else {
        cout << "no\n";
    }

    return 0;
}
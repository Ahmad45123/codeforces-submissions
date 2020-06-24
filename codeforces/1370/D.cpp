#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(int x, int t, vector<int> arr, int k) {
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(t == 0) {
            cnt ++;
            t = !t;
        } else {
            if(arr[i] <= x) {
                cnt ++;
                t = !t;
            }
        }
    }
    return cnt >= k;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int l = *min_element(arr.begin(), arr.end());
    int r = *max_element(arr.begin(), arr.end());
    while(l < r) {
        int mid = l+(r-l)/2;
        if(isPossible(mid, 0, arr, k) || isPossible(mid, 1, arr, k)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    cout << l << "\n";

    return 0;
}
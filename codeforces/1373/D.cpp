#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll attemptOne(vector<int> arr) {
    vector<int> tmp;
    for(int i = 1; i < arr.size(); i += 2) {
        tmp.push_back(arr[i]-arr[i-1]);
    }
    ll ans = 0;
    ll soFar = 0;
    for(int i = 0; i < tmp.size(); i++) {
        soFar += tmp[i];
        if(soFar < 0) {
            soFar = 0;
        } else if(soFar > ans) {
            ans = soFar;
        }
    }
    return ans;
}

ll attemptTwo(vector<int> arr) {
    vector<int> tmp;
    for(int i = 1; i < arr.size(); i += 2) {
        if(i+1 < arr.size())
            tmp.push_back(arr[i]-arr[i+1]);
    }
    ll ans = 0;
    ll soFar = 0;
    for(int i = 0; i < tmp.size(); i++) {
        soFar += tmp[i];
        if(soFar < 0) {
            soFar = 0;
        } else if(soFar > ans) {
            ans = soFar;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        
        if(n == 1) {
            cout << arr[0] << "\n";
            continue;
        }

        ll origSum = 0;

        for(int i = 0; i < n; i += 2) {
            origSum += arr[i];
        }

        ll tmp1 = attemptOne(arr);
        ll tmp2 = attemptTwo(arr);

        cout << origSum+max(max(0LL, tmp1), tmp2) << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int countDiffOne(vector<int> arr) {
    int ans = 0;
    for(int i = 0; i < arr.size(); i++)
        for(int j = i+1; j < arr.size(); j++) {
            if(abs(arr[i]-arr[j]) == 1)
                ans ++;
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
        int even = 0, odd = 0;
        for(auto &x : arr) {
            cin >> x;
            if(x % 2 == 0)
                even ++;
            else
                odd ++;
        }
        even %= 2;
        odd %= 2;
        if((even == 0 && odd == 0) || (even == 1 && odd == 1 && countDiffOne(arr) > 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }   
    
    return 0;
}
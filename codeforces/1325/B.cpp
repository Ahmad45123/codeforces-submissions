#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> arr(n);
        for(auto &x : arr)
            cin >> x;
        
        sort(arr.begin(), arr.end());
        auto end = unique(arr.begin(), arr.end());

        cout << arr.size()-(arr.end()-end) << "\n";
    }
    
    
    return 0;
}
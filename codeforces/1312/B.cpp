#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(int a, int b) {
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end(), comp);

        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    
    return 0;
}
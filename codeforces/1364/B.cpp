#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;

        for(int i = 1; i < n-1; i++) {
            if(abs(arr[i]-arr[i-1])+abs(arr[i]-arr[i+1]) <= abs(arr[i-1]-arr[i+1])) {
                arr.erase(arr.begin()+i);
                i --;
                n --;
            }
        }

        cout << arr.size() << "\n";
        for(int x : arr)
            cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}
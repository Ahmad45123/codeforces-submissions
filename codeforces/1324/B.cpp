#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        arr = vector<int>(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        bool good = false;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[i] == arr[j] && j-i-1 >= 1) {
                    good = true;
                    break;
                }
            }
        }

        if(good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}
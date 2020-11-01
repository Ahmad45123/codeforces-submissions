#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<int> arr1(n);
        for(int &a : arr1)
            cin >> a;
        
        vector<int> arr2(n);
        for(int &a : arr2)
            cin >> a;
        
        for(int &a : arr1) {
            a = x - a;
        }

        vector<bool> sel(n);

        bool bad = false;

        // for each arr1
        for(int i = 0; i < n; i++) {
            int selJ = -1;
            int vl = 0;
            for(int j = 0; j < n; j++) {
                if(sel[j]) continue;
                if(arr2[j] <= arr1[i] && arr2[j] > vl) {
                    vl = arr2[j];
                    selJ = j;
                }
            }
            if(selJ == -1) {
                bad = true;
                break;
            } else {
                sel[selJ] = true;
            }
        }

        cout << (bad ? "No\n" : "Yes\n");
    }
    
    return 0;
}
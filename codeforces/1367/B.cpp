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
        int nOdd = 0;
        int nEven = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] % 2 == 0)
                nEven ++;
            else
                nOdd ++;
        }

        if(nEven == nOdd || nOdd+1 == nEven) {
            int cntNotPlace = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i] % 2 != i % 2)
                    cntNotPlace ++;
            }
            cout << cntNotPlace/2 << "\n";
        } else {
            cout << -1 << "\n";
        }

    }
    
    return 0;
}
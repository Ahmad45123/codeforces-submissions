#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> arr(n, vector<int>(n));
        int j = 0;
        int nxt = 1;
        bool isZero = (k % n == 0);
        while(k > 0) {
            for(int i = 0; i < n; i++) {
                arr[i][j] = 1;
                k --;
                if(k == 0)
                    break;
                j ++;
                if(j >= n) {
                    j = 0;
                }
            }
            j = nxt++;
        }

        if(isZero)
            cout << "0\n";
        else
            cout << "2\n";
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << arr[i][j];
            cout << "\n";
        }        
    }
    
    return 0;
}
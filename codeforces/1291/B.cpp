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
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<int> tmp(n);
        int cur = -1;
        for(int i = 0; i < n; i++) {
            if(i > n/2) {
                cur --; 
            } else {
                cur ++;
            }
            tmp[i] = cur;

            if(i == n/2 && n % 2 == 0) {
                cur -= 1;
            }
        }

        bool good = true;
        for(int i = 0; i < n; i++) {
            if(arr[i] < tmp[i])
            {
                good = false;
                break;
            }
        }

        if(good == false && n % 2 == 0) {
            swap(tmp[n/2], tmp[(n/2)-1]);
            good = true;
            for(int i = 0; i < n; i++) {
                if(arr[i] < tmp[i])
                {
                    good = false;
                    break;
                }
            }
        }

        if(good)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    
    return 0;
}
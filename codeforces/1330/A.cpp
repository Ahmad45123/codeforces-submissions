#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t --) {
        int n, rem; cin >> n >> rem;
        vector<int> arr(n);
        for(int &i : arr)
            cin >> i;
        
        sort(arr.begin(), arr.end());

        int exp = 1;

        for(int i = 0; i < n; i++){
            if(i > 0 && arr[i] == arr[i-1]) {
                continue;
            }

            if(arr[i] == exp) {
                exp ++;
            } else {
                while(exp < arr[i] && rem > 0) {
                    exp++;
                    rem--;
                }
                if(exp != arr[i]) {
                    break;
                }
                exp ++;
            }
        }
        
        exp --;
        exp += rem;

        cout << exp << "\n";
    }
    
    return 0;
}
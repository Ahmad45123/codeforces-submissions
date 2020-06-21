#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;;
        vector<int> arr(n*2);
        for(int &x : arr)
            cin >> x;
        vector<int> even;
        vector<int> odd;
        for(int i = 0; i < 2*n; i++) {
            if(arr[i] % 2 == 0) {
                even.push_back(i+1);
            } else {
                odd.push_back(i+1);
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < even.size(); i += 2) {
            if(i+1 >= even.size())
                break;
            cout << even[i] << " " << even[i+1] << "\n";
            cnt++;
            if(cnt == n-1)
                break; 
        }
        
        if(cnt != n-1)
        for(int i = 0; i < odd.size(); i += 2) {
            if(i+1 >= odd.size())
                break;
            cout << odd[i] << " " << odd[i+1] << "\n"; 
            cnt++;
            if(cnt == n-1)
                break;
        }
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(auto &i : arr1)
        cin >> i;
    
    for(auto &i : arr2)
        cin >> i;
    
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        if(arr1[i] == arr2[i])
            continue;
        else if(arr1[i] == 1)
            a ++;
        else if(arr2[i] == 1)
            b ++;
    }

    for(int i = 1; i <= 1000; i++) {
        if(i*a > b) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";

    return 0;
}
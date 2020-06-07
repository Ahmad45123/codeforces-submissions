#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(2*n);
    for(auto &x : arr)
        cin >> x;
    
    ll sum1 = 0;
    ll sum2 = 0;
    for(int i = 0; i < n; i++) {
        sum1 += arr[i];
        sum2 += arr[i+n];
    }

    if(sum1 != sum2) {
        for(int i = 0; i < 2*n; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return 0;
    }
    
    int found = false;
    for(int i = 0; i < n; i++) {
        for(int j = n; j < 2*n; j++) {
            if(arr[i] != arr[j]) {
                swap(arr[i], arr[j]);
                found = true;
                break;
            }
        }
        if(found)
            break;
    }

    if(found) {
        for(int i = 0; i < 2*n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
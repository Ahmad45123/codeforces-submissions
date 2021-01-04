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
        sort(arr.begin(), arr.end(), greater<int>());
        ll evenSum = 0;
        ll oddSum = 0;
        for(int i = 0; i < n; i++) {
            if((arr[i] % 2) == 0 && (i % 2) == 0) {
                evenSum += arr[i];
            } else if((arr[i] % 2) == 1 && (i%2) == 1) {
                oddSum += arr[i];
            }
        }
        if(evenSum == oddSum) cout << "Tie\n";
        else cout << (evenSum > oddSum ? "Alice\n" : "Bob\n");
    }
    
    return 0;
}
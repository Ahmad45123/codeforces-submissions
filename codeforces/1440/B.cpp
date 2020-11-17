#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    vector<int> arr(n*k);
    for(int &x : arr)
      cin >> x;
    
    reverse(arr.begin(), arr.end());

    int toSkip = n-ceil(n*1.0/2.0);

    long long int ans = 0;

    for(int i = toSkip; i < arr.size() && k > 0; i += toSkip+1) {
      // cout << i << " " << arr[i] << "\n";
      ans += arr[i];
      k --;
    }

    cout << ans << "\n";
  }
}
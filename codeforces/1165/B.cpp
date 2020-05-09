#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> arr(n);
  for(auto &x : arr)
    cin >> x;
  sort(arr.begin(), arr.end());
  int ans = 0;
  int cur = 1;
  for(int i = 0; i < n; i++) {
    if(arr[i] >= ans+1)
      ans ++;
  }
  cout << ans;
}
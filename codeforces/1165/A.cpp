#include <iostream>

using namespace std;

int main() {
  int n, x, y; cin >> n >> x >> y;
  string s; cin >> s;
  int tmp = 0;
  int ans = 0;
  for(int i = n-1; i >= n-x; i--) {
    if(tmp == y) {
      if(s[i] == '0')
        ans ++;
    } else {
      if(s[i] == '1')
        ans ++;
    }
    tmp ++;
  } 
  cout << ans << "\n";
}
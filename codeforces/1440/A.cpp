#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int n, c0, c1, h; cin >> n >> c0 >> c1 >> h;
    string s; cin >> s;
    int ones = 0, zeros = 0;
    for(char c : s)
      if(c == '0')
        zeros ++;
      else
        ones ++;
    
    cout << min(zeros*c0 + ones*c1, min(zeros*h + (ones+zeros)*c1, ones*h + (ones+zeros)*c0)) << "\n";
  }
}
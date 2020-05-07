#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int arr1[] = {a, b};
    int arr2[] = {c, d};
    
    bool good = false;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++) {
        if(arr1[i]==arr2[j] && arr1[!i]+arr2[!j]==arr1[i])
          good = true;
      }
    
    if(good)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
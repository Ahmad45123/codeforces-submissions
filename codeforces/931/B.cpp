#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, a, b; cin >> n >> a >> b; a--; b--;
    int meet = 0;
    while(a != b) {
    	a /= 2;
    	b /= 2;
    	meet ++;
    }
    if(meet == log2(n))
      cout << "Final!\n";
    else
      cout << meet << "\n";
    
    return 0;
}
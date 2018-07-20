#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n; cin >> n;
    int a = 0;
    for(int i = 0; i < n; i++) {
        cout << a;
        a = 1-a;
    }
    return 0;
}
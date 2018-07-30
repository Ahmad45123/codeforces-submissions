#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n; cin >> n;
    int sum1 = 0;
    for(int i = 0; i < n; i++) {
        int j; cin >> j; sum1 += j;
    }
    
    int sum2 = 0;
    for(int i = 0; i < n; i++) {
        int j; cin >> j; sum2 += j;
    }
    
    if(sum1 >= sum2) 
        cout << "Yes";
    else
        cout << "No";
    
    return 0;
}
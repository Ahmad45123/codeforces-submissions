#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int endTime = 0;

int main()
{
    int n, k; cin >> n >> k;
    
    endTime = (4*60)-k;
    int curTime = 0;
    
    int i = 1;
    while(i <= n && endTime > curTime) {
        if(curTime + i*5 > endTime)
            break;
        curTime += i*5;
        i++;
    }

    cout << i-1;

    return 0;
}
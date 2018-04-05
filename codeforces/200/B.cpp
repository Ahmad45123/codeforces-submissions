#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    int n; cin >> n;
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        sum += a;
    }

    cout << sum / n;
    
    int xyz; cin >> xyz; return 0;
}
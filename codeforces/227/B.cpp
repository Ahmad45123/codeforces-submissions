#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    map<int, int> numbers;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        numbers[tmp] = i;
    }

    int m; cin >> m;
    ll vasya = 0, petya = 0;
    while(m--) {
        int needed; cin >> needed;
        vasya += numbers[needed]+1;
        petya += n-numbers[needed];
    }

    cout << vasya << " " << petya; 
    
    return 0;
}
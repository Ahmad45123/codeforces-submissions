#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> powers;
    int tmp = 1;
    for(int i = 0; tmp <= 1e9; i++, tmp = pow(2, i))
        powers.push_back(tmp);

    int n; cin >> n;
    
    auto it = lower_bound(powers.begin(), powers.end(), n);
    if(*it == n)
        cout << it-powers.begin()+1 << '\n';
    else
        cout << it-powers.begin() << '\n';
    
    return 0;
}
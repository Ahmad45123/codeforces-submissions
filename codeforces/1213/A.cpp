#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    int n; cin >> n;
    vector<ll> nums(n);
    int ev = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i] % 2 == 0)
            ev++;
    }

    cout << min(ev, n-ev) << "\n";
    int xyz; cin >> xyz; return 0;
}
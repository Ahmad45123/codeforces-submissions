#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll n; cin >> n;
    vector<int> arr(n);

    cout << "AND 1 2" << endl; 
    ll AND1; cin >> AND1;
    
    cout << "XOR 1 2" << endl; 
    ll XOR1; cin >> XOR1;

    ll sum1 = XOR1 + 2*AND1;
    
    cout << "AND 2 3" << endl; 
    ll AND2; cin >> AND2;
    
    cout << "XOR 2 3" << endl; 
    ll XOR2; cin >> XOR2;

    ll sum2 = XOR2 + 2*AND2;

    cout << "AND 1 3" << endl; 
    ll AND3; cin >> AND3;
    
    ll XOR3 = XOR1^XOR2;

    ll sum3 = XOR3 + 2*AND3;
    
    arr[0] = (sum1-sum2+sum3)/2;
    arr[1] = sum1-arr[0];
    arr[2] = sum3-arr[0];

    for(int i = 3; i < n; i++) {
        cout << "XOR 1 " << i+1 << endl;
        ll v; cin >> v;
        arr[i] = v^arr[0];
    }

    cout << "! ";
    for(int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
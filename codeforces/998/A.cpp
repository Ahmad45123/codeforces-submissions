#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

bool comp(int a, int b) {
    return a > b;
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    int tmp = INT_MAX;
    int ans = -1;
    for(int i = 0; i < n; i++) { 
        cin >> arr[i];
        if(arr[i] < tmp) {
            tmp = arr[i];
            ans = i+1;
        }
    }

    if(n == 1) {
        cout << -1;
    }
    else if(n == 2 && arr[0] == arr[1])
        cout << -1;
    else {
        cout << 1 << endl << ans;
    }
    return 0;
}
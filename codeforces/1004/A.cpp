#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n, d; cin >> n >> d;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int ans = 2;
    for(int i = 1; i < n; i++) {
        int dif = arr[i]-arr[i-1];
        if(dif > 2*d) {
            ans += 2;
        }
        else if(dif == 2*d) {
            ans += 1;
        }
    }

    cout << ans;
    return 0;
}
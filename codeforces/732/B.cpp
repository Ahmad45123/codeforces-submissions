#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int changed = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i-1] + arr[i] < k) {
            int diff = k - (arr[i-1] + arr[i]);
            changed += diff;
            arr[i] += diff;
        }
    }

    cout << changed << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
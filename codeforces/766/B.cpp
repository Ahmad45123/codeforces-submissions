#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    //1,2,3,4,5

    bool good = false;

    for(int i = 1; i < n; i++) {
        int num1 = arr[i-1];
        int num2 = arr[i];
        for(int j = i+1; j < n; j++) {
            int num3 = arr[j];
            if(num3 < num1+num2) {
                good = true;
                break;
            }
        }
        if(good)
            break;
    }    
    
    if(good)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
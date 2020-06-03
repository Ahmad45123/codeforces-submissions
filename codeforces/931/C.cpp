#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    int mn = 1e9, mx = -1e9;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    if(abs(mx-mn) <= 1) {
        cout << n << "\n";
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    } else { // diff is 2
        int nMin = 0;
        int nMid = 0;
        int nMax = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] == mn)
                nMin ++;
            else if(arr[i] == mx)
                nMax ++;
            else
                nMid ++;

        int half = nMid/2;
        if(half > min(nMin, nMax)) {

            cout << n-2*half << "\n";
            nMin = nMax = half;
            for(int i = 0; i < n; i++) {
                if(arr[i] == mn+1 && nMin > 0) {
                    cout << arr[i]-1 << " ";
                    nMin --;
                } else if(arr[i] == mn+1 && nMax > 0) {
                    cout << arr[i]+1 << " ";
                    nMax --;
                } else {
                    cout << arr[i] << " ";
                }
            }

        } else {
            cout << n-2*min(nMin, nMax) << "\n";
            nMin = nMax = min(nMin, nMax);
            for(int i = 0; i < n; i++) {
                if(arr[i] == mn && nMin > 0) {
                    cout << arr[i]+1 << " ";
                    nMin --;
                } else if(arr[i] == mx && nMax > 0) {
                    cout << arr[i]-1 << " ";
                    nMax --;
                } else {
                    cout << arr[i] << " ";
                }
            }
        }
    }
    return 0;
}
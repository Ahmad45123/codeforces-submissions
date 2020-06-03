#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    int mn = 1e9, mx = -1e9, av = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
        av = (mn+mx)/2;
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

        int tmp1 = nMid/2;
        int tmp2 = min(nMin, nMax);

        if(tmp1 > tmp2) {  
            cout << n-2*tmp1 << "\n";
            nMin += tmp1;
            nMax += tmp1;
            nMid -= tmp1*2;
        } else {
            cout << n-2*tmp2 << "\n";
            nMin -= tmp2;
            nMax -= tmp2;
            nMid += tmp2*2;
        }

        for(int i = 0; i < nMin; i++)
            cout << mn << " ";
        for(int i = 0; i < nMax; i++)
            cout << mx << " ";
        for(int i = 0; i < nMid; i++)
            cout << av << " ";
        cout << "\n";

    }
    return 0;
}
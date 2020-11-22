#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> xors(n);
    map<int, int> xorset;
    vector<int> arr(n, -1);
    int eqIdx1 = -1, eqIdx2 = -1;
    for(int i = 1; i < n; i++) {
        cout << "XOR 1 " << i+1 << endl;
        cin >> xors[i];
        if(xorset.find(xors[i]) != xorset.end()) {
            eqIdx1 = xorset.find(xors[i])->second;
            eqIdx2 = i;
        }
        xorset[xors[i]] = i;
    }

    if(eqIdx1 != -1) {
        cout << "AND " << eqIdx1+1 << " " << eqIdx2+1 << endl;
        int tmp; cin >> tmp;
        arr[0] = xors[eqIdx1]^tmp;
    } else {
        int zeroAndIdx = -1;
        int diffIdx = -1;
        for(int i = 1; i < n; i++)
            if(xors[i] == n-1)
                zeroAndIdx = i;
            else
                diffIdx = i;
        int smFirstAndZeroAnd = n-1;
        cout << "AND " << diffIdx+1 << " " << 1 << endl;
        int tmp; cin >> tmp;
        int smFirstAndDiff = xors[diffIdx] + 2 * tmp;
        
        cout << "AND " << diffIdx+1 << " " << zeroAndIdx+1 << endl;
        cin >> tmp;
        int smDiffAndZeroAnd = (xors[diffIdx]^xors[zeroAndIdx]) + 2 * tmp;

        tmp = (smFirstAndZeroAnd - smDiffAndZeroAnd + smFirstAndDiff)/2;
        arr[0] = tmp;
    }

    cout << "! " << arr[0] << " ";
    for(int i = 1; i < n; i++) {
        cout << (xors[i]^arr[0]) << " ";
    }
    cout << endl;

    return 0;
}
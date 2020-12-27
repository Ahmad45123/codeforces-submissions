#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(int j, int &k, vector<short> &arr) {
    int ansR = (arr[j] != 0);
    int exp = 1;
    for(int i = j+1; i < j+k; i++) {
        if(arr[i] != exp)
            ansR ++;
        exp++;
        exp %= 3;
    }
    
    int ansG = (arr[j] != 1);
    exp = 2;
    for(int i = j+1; i < j+k; i++) {
        if(arr[i] != exp)
            ansG ++;
        exp++;
        exp %= 3;
    }
    
    int ansB = (arr[j] != 2);
    exp = 0;
    for(int i = j+1; i < j+k; i++) {
        if(arr[i] != exp)
            ansB ++;
        exp++;
        exp %= 3;
    }

    return min({ansR, ansG, ansB});
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q; cin >> q;
    while(q--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<short> arr;
        for(char c : s) {
            if(c == 'R')
                arr.push_back(0);
            else if(c == 'G')
                arr.push_back(1);
            else
                arr.push_back(2);
        }
        
        int ans = n;
        for(int i = 0; i <= n-k; i++)
            ans = min(ans, solve(i, k, arr));

        cout << ans << "\n";
    }
    
    return 0;
}
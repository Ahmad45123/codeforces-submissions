#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<int> arr;
    arr.push_back(2);
    int i = 2;
    while(arr[arr.size()-1] < 1e9) {
        int tmp = (i*(3*i+1))/2;
        arr.push_back(tmp);
        i ++;
    }

    int t; cin >> t;
    while(t--) {
        int c; cin >> c;
        int pyramids = 0;
        for(i = arr.size()-1; i >= 0; i--) {
            if(arr[i] <= c && c > 0) {
                pyramids += (c/arr[i]);
                c = c % arr[i];
            }
        }
        cout << pyramids << "\n";
    }
    
    return 0;
}
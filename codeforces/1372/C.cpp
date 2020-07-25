#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(auto &x : arr)
            cin >> x;

        int start = 0;
        while(start+1 == arr[start] && start < n)
            start ++;
        int end = n-1;
        while(end+1 == arr[end] && end >= 0)
            end --;

        if(end <= start) {
            cout << "0\n";
            continue;
        }

        int inPlace = 0;
        for(int i = start; i <= end; i++) {
            if(arr[i] == i+1) {
                inPlace ++;
            }
        }

        if(inPlace == 0) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    
    return 0;
}
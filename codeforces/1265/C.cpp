#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> arr(n);
        for(int &x : arr)
            cin >> x;
        
        vector<int> count;
        int tmp = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i-1]) {
                count.push_back(tmp);
                tmp = 1;
            } else {
                tmp ++;
            }
        }
        count.push_back(tmp);

        ll tmpSum = 0;
        int j = -1;
        for(int i = 0; i < count.size(); i++) {
            tmpSum += count[i];
            if(tmpSum > n/2) {
                j = i;
                break;
            }
        }

        if(j < 3) {
            cout << "0 0 0\n";
            continue;
        }

        int g = 0, s = 0, b = 0;
        g = count[0];
        int i = 1;
        for(; i < j && s <= g; i ++)
            s += count[i];
        for(; i < j; i ++)
            b += count[i];
        
        if(g >= s || g >= b || g == 0 || s == 0 || b == 0) {
            cout << "0 0 0\n";
        } else {
            cout << g << " " << s << " " << b << "\n";
        }
    }
    
    return 0;
}
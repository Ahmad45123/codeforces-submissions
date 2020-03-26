#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        
        string a = "", b = "";
        bool equal = true;

        for(int i = 0; i < n; i++) {
            int x = str[i];
            if(x == '0') {
                a += '0', b += '0';
            } else if(x == '1') {
                if(equal) {
                    a += '1';
                    b += '0';
                    equal = false;
                } else {
                    a += '0';
                    b += '1';
                }
            } else if(x == '2') {
                if(equal) {
                    a += '1', b += '1';
                } else {
                    a += '0';
                    b += '2';
                }
            }
        }

        cout << a << "\n" << b << "\n";
    }
    
    return 0;
}
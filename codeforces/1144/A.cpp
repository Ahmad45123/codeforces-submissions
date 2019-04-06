#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        bool good = true;
        for(int i = 1; i < s.size(); i++) {
            if(s[i]-1 != s[i-1]) {
                good = false;
                break;
            }
        }
        if(good)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    int xyz; cin >> xyz; return 0;
}
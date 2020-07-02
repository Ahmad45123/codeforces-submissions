#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string solve(string s) {
    if(s.size() == 1)
        return s;
    if(s[0] == '1' && s[s.size()-1] == '0') {
        return "0";
    } else {
        int start = 0, end = s.size()-1;
        while(s[start] == '0')
            start ++;
        while(s[end] == '1')
            end --;
        if(end <= start) {
            return s;
        } else {
            string b = s.substr(0, start);
            string e = s.substr(end+1);
            string mid = s.substr(start, end - start + 1);
            return b + solve(mid) + e;
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        cout << solve(s) << "\n";
    }
    
    return 0;
}
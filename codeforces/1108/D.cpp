#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) {
            cnt ++;
            bool red = true, green = true, blue = true;
            if(s[i-1] == 'R')
                red = false;
            if(s[i-1] == 'G')
                green = false;
            if(s[i-1] == 'B')
                blue = false;
            if(i+1<n && s[i+1] == 'R')
                red = false;
            if(i+1<n && s[i+1] == 'G')
                green = false;
            if(i+1<n && s[i+1] == 'B')
                blue = false;
            
            if(red)
                s[i] = 'R';
            else if(green)
                s[i] = 'G';
            else if(blue)
                s[i] = 'B';
        }
    }
    
    cout << cnt << "\n" << s << "\n";

    return 0;
}
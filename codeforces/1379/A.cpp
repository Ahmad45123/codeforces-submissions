#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int countAbac(string s) {
    int fnd = 0;
    //check if occurs once.
    size_t pos = s.find("abacaba");
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Add position to the vector
        fnd ++;
        // Get the next occurrence from the current position
        pos =s.find("abacaba", pos+1);
    }
    
    return fnd;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        int fnd = countAbac(s);

        if(fnd > 1) {
            cout << "No\n";
            continue;
        } else if(fnd == 1) {
            for(int i = 0; i < n; i++) {
                if(s[i] == '?') {
                    s[i] = 'z';
                }
            }
            cout << "Yes\n";
            cout << s << "\n";
            continue;
        }

        for(int i = 6; i < n; i ++) {
            bool good = true;
            string l = "abacaba";
            for(int j = 0; j < 7; j ++) {
                if(s[i-j] != l[6-j] && s[i-j] != '?') {
                    good = false;
                    break;
                }
            }
            if(good) {
                string tmp = s;
                for(int j = 0; j < 7; j ++) {
                    if(tmp[i-j] == '?') {
                        tmp[i-j] = l[6-j];
                    }
                }
                if(countAbac(tmp) == 1) {
                    s = tmp;
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                s[i] = 'z';
            }
        }

        fnd = countAbac(s);

        if(fnd == 1) {
            cout << "Yes\n";
            cout << s << "\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}
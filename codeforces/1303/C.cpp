#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INT_INF 1e9
#define LL_INF 1e18

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        
        vector<char> chars;
        int curIndex = 0;
        chars.push_back(s[0]);

        bool bad = false;

        for(int i = 1; i < s.size(); i++) {
            char left = (curIndex-1 >= 0 ? chars[curIndex-1] : ' ');;
            char right = (curIndex+1 < chars.size() ? chars[curIndex+1] : ' ');
            if(left == s[i]) {
                curIndex --;
            } else if(s[i] == right) {
                curIndex ++;
            } else if(right == ' ') {
                curIndex ++;
                if(curIndex < chars.size())
                    chars[curIndex] = s[i];
                else
                    chars.push_back(s[i]);
            } else if(left == ' ') {
                curIndex --;
                if(curIndex >= 0)
                    chars[curIndex] = s[i];
                else {
                    chars.insert(chars.begin(), s[i]);
                    curIndex = 0;
                }
            } else {
                bad = true;
                break;
            }
        }

        for(char c = 'a' ; c <= 'z'; c++) {
            int cnt = count(chars.begin(), chars.end(), c);
            if(cnt == 0) {
                chars.push_back(c);
            } else if(cnt > 1) {
                bad = true;
                break;
            }
        }

        if(bad) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for(char c : chars)
                if(c != '?')
                    cout << c;
            cout << "\n";
        }
    }
    
    return 0;
}
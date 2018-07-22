#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    string s; cin >> s;
    
    bool ab = false;
    bool ba = false;
    int both = 0;

    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] == 'A' && s[i+1] == 'B') {
            if(i+2 < s.size() && s[i+2] == 'A') {
                both++;
                i+=2;
            }
            else
                ab = true;
        }
        else if(s[i] == 'B' && s[i+1] == 'A') {
            if(i+2 < s.size() && s[i+2] == 'B') {
                both++;
                i+=2;
            }
            else
                ba = true; 
        }
    }

    if((ab && ba) || (ab && both == 1) || (ba && both == 1) || both >= 2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
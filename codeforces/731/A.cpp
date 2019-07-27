#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);

    string input; cin >> input;
    char cur = 'a';
    int res = 0;
    for(int i = 0; i < input.length(); i++) {
        char c = input[i];
        if(abs(c-cur) <= 13)
            res += abs(c-cur);
        else
            res += 26 - abs(c-cur);
        cur = c;
    }
    cout << res;

    int test123; cin >> test123; return 0;
}
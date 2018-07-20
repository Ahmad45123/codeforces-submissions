#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    int n; string s; cin >> n; cin >> s;

    vector<char> ans;
    bool type = false;
    for(int i = 0; i < n; i++) {
        if(type == false) {
            ans.push_back(s[i]);
        }
        else {
            ans.insert(ans.begin(), s[i]);
        }
        type = !type;
    }

    if(n % 2 == 0)
        copy(ans.rbegin(), ans.rend(), ostream_iterator<char>(cout));
    else
        copy(ans.begin(), ans.end(), ostream_iterator<char>(cout));
    cout << endl;
    return 0;
}
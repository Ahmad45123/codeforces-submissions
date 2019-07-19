#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int a = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;
        if(c == 'A') {
            a++;
        } else {
            d++;
        }
    }
    
    if(a > d) {
        cout << "Anton";
    } else if(a < d) {
        cout << "Danik";
    } else {
        cout << "Friendship";
    }

    return 0;
}
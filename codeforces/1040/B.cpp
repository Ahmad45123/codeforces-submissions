#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<int> ans;

    int toMinus = 0;
    while(k-toMinus >= 0) {
        int rem = n-((k-toMinus)+k+1);
        while(rem >= 2*k+1) {
            rem -= 2*k+1;
        }
        if(rem < 0) {
            cout << 1 << '\n';
            int tes = min(k+1, n);
            cout << tes << '\n';
            return 0;
        }
        if(rem == 0 || rem > k) {
            //good sln
            ans.push_back(k-toMinus+1);
            bool now = false;
            for(int i = k-toMinus+k+2; i <= n; i+=k) {
                if(now) {
                    ans.push_back(i);
                    i++;
                    now = false;
                }
                else
                    now = true;
            }
            break;
        }

        toMinus++;
    }
    
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
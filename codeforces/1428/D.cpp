#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    if(arr[n] > 1) {
        cout << "-1\n";
        return 0;
    }

    vector<pair<int, int>> ans;
    queue<int> hasOnesForTwo;
    queue<int> hasOnesForThree;
    bool good = true;

    for(int c = n; c >= 1; c--) {
        if(arr[c] == 0) {
            // empties.push(c);
        } else if(arr[c] == 1) {

            ans.push_back({c, c});
            hasOnesForTwo.push(c);
            // hasOnesForThree.push(c);

        } else if(arr[c] == 2) {

            if(hasOnesForTwo.size() > 0) {
                ans.push_back({hasOnesForTwo.front(), c});
                hasOnesForTwo.pop();
                hasOnesForThree.push(c);
            } else {
                good = false;
                break;
            }

        } else if(arr[c] == 3) {

            if(hasOnesForThree.empty()) {
                if(hasOnesForTwo.empty()) {
                    good = false;
                    break;
                } else {
                    // We place 2 nodes, one at  top and one at right in one of has ones
                    ans.push_back({c, c});
                    ans.push_back({c, hasOnesForTwo.front()});
                    hasOnesForTwo.pop();

                    // Place the new has one.
                    hasOnesForThree.push(c);
                }
            } else {
                // We place 2 nodes, one at  top and one at right in one of has ones
                ans.push_back({c, c});
                ans.push_back({c, hasOnesForThree.front()});
                hasOnesForThree.pop();

                // Place the new has one.
                hasOnesForThree.push(c);
                // hasOnesForTwo.push(c);
            }
        }
    }

    if(!good) {
        cout << "-1\n";
    } else {
        cout << ans.size() << "\n";
        for(auto x : ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    
    return 0;
}
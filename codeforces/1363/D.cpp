#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{    
    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        vector<vector<int>> subsets(k, vector<int>());
        for(int i = 0; i < k; i++) {
            int c; cin >> c;
            subsets[i].resize(c);
            for(int j = 0; j < c; j++)
                cin >> subsets[i][j];
        }

        cout << "? " << n << " "; cout.flush();
        for(int i = 1; i <= n; i++) {
            cout << i << " ";
            cout.flush();
        }
        cout << "\n"; cout.flush();
        int mxValue; cin >> mxValue;
        if(mxValue == -1)
            return 0;

        int l = 1, r = n;
        while(l <= r) {
            int mid = l+(r-l)/2;

            cout << "? " << mid-l+1 << " "; cout.flush();
            for(int i = l; i <= mid; i++) {
                cout << i << " ";
                cout.flush();
            }
            cout << "\n"; cout.flush();
            int maxValueLeft; cin >> maxValueLeft;
            if(maxValueLeft == -1)
                return 0;

            if(maxValueLeft == mxValue) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        vector<int> ans;
        for(int i = 0; i < k; i++) {
            bool fnd = false;
            int val = mxValue;
            for(int j = 0; j < subsets[i].size(); j++) {
                if(subsets[i][j] == l) {
                    fnd = true;
                }
            }

            if(fnd) {
                vector<bool> mark(1001);
                for(int j = 0; j < subsets[i].size(); j++) {
                    mark[subsets[i][j]] = true;
                }
                cout << "? " << n-subsets[i].size() << " "; cout.flush();
                for(int i = 1; i <= n; i++) {
                    if(mark[i] == true) continue;
                    cout << i << " ";
                    cout.flush();
                }
                cout << "\n"; cout.flush();
                cin >> val;
                if(val == -1)
                    return 0;
            }

            ans.push_back(val);
        }

        cout << "! "; cout.flush();
        for(int i = 0; i < k; i++) {
            cout << ans[i] << " ";
            cout.flush();
        }
        cout << "\n"; cout.flush();
        string res; cin >> res;
        if(res != "Correct")
            return 0;
    }
       
    return 0;
}
    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;

    int getMex(vector<int> arr) {
        bool vis[1002] = {};
        for(int i = 0; i < arr.size(); i++) {
            vis[arr[i]] = true;
        }
        for(int i = 0; i <= 1001; i++) {
            if(vis[i] == false)
                return i;
        }
        return -1;
    }

    bool isIncreasing(vector<int> arr) {
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] < arr[i-1])
                return false;
        }
        return true;
    }

    int main()
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
        int t; cin >> t;
        while(t--) {
            int n; cin >> n;
            vector<int> arr(n);
            for(int i = 0; i < n; i++)
                cin >> arr[i];
            
            vector<int> ans;

            for(int tmp = 0; tmp <= 2*n; tmp ++) {
                if(isIncreasing(arr))
                    break;
                int mex = getMex(arr);
                if(mex == n) {
                    int t = 0;
                    while(arr[t] == t && t < n)
                        t++;
                    arr[t] = mex;
                    ans.push_back(t);
                } else {
                    arr[mex] = mex;
                    ans.push_back(mex);
                }
            }

            cout << ans.size() << "\n";
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i]+1 << " ";
            }
            cout << "\n";

        }
        
        return 0;
    }
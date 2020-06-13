#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    queue<int> notReqNums;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1])
            continue;
        for(int j = arr[i-1]+1; j <= arr[i]-1; j++)
            notReqNums.push(j);
    }

    int next = 0;
    unordered_map<int, bool> added;
    vector<int> ans;

    if(arr[0]-1 > n) {
        cout << -1 << "\n";
        return 0;       
    }
    
    if(arr[0] == 0) {
        if(!notReqNums.empty()) {
            ans.push_back(notReqNums.front());
            added[notReqNums.front()] = true;
            notReqNums.pop(); 
        } else {
            ans.push_back(1e5+1);
        }
    } else {
        while(arr[0] != next) {
            ans.push_back(next);
            added[next] = true;
            while(added[next])
                next ++;
        }
    }


    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
            if(!notReqNums.empty()) {
                ans.push_back(notReqNums.front());
                added[notReqNums.front()] = true;
                notReqNums.pop();
            } else {
                ans.push_back(ans[ans.size()-1]);
            }
            while(added[next])
                next ++;
        } else {
            while(arr[i] != next) {
                ans.push_back(next);
                added[next] = true;
                while(added[next])
                    next ++;
            }
        }
    }

    if(ans.size() != n) {
        cout << -1 << "\n";
        return 0;
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}
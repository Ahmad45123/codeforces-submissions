#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{   
    int nums[6] = {4, 8, 15, 16, 23, 42};
    map<int, pair<int, int>> arr;
    for(int i = 0; i < 6; i ++)
        for(int j = i+1; j < 6; j++)
            arr[nums[i]*nums[j]] = {nums[i], nums[j]};

    vector<int> ans(7);

    cout << "? 1 2\n"; cout.flush();
    int pair1; cin >> pair1;
    cout << "? 2 3\n"; cout.flush();
    int pair2; cin >> pair2;
    if(arr[pair1].first == arr[pair2].first) {
        ans[2] = arr[pair1].first;
        ans[1] = arr[pair1].second;
        ans[3] = arr[pair2].second;
    } else if(arr[pair1].first == arr[pair2].second) {
        ans[2] = arr[pair1].first;
        ans[1] = arr[pair1].second;
        ans[3] = arr[pair2].first;
    } else if(arr[pair1].second == arr[pair2].first) {
        ans[2] = arr[pair1].second;
        ans[1] = arr[pair1].first;
        ans[3] = arr[pair2].second;
    } else if(arr[pair1].second == arr[pair2].second) {
        ans[2] = arr[pair1].second;
        ans[1] = arr[pair1].first;
        ans[3] = arr[pair2].first;
    }
    
    cout << "? 4 5\n"; cout.flush();
    cin >> pair1;
    cout << "? 5 6\n"; cout.flush();
    cin >> pair2;
    if(arr[pair1].first == arr[pair2].first) {
        ans[5] = arr[pair1].first;
        ans[4] = arr[pair1].second;
        ans[6] = arr[pair2].second;
    } else if(arr[pair1].first == arr[pair2].second) {
        ans[5] = arr[pair1].first;
        ans[4] = arr[pair1].second;
        ans[6] = arr[pair2].first;
    } else if(arr[pair1].second == arr[pair2].first) {
        ans[5] = arr[pair1].second;
        ans[4] = arr[pair1].first;
        ans[6] = arr[pair2].second;
    } else if(arr[pair1].second == arr[pair2].second) {
        ans[5] = arr[pair1].second;
        ans[4] = arr[pair1].first;
        ans[6] = arr[pair2].first;
    }

    cout << "! ";
    for(int i = 1; i <= 6; i++)
        cout << ans[i] << " ";
    cout << "\n"; cout.flush();

    return 0;
}
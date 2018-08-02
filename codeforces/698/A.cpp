#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
typedef long long int ll;

int n;
vector<int> arr;

int dp[101][3];

//curr => 0, 1
int solve(int i, int curr) {
    if(i >= n)
        return 0;

    int &ret = dp[i][curr];
    if(~ret)
        return ret;
    
    if(arr[i] == 3) {
        ret = 1+solve(i+1, 0);
        if(curr != 2)
            ret = min(ret, solve(i+1, 2));
        if(curr != 1)
            ret = min(ret, solve(i+1, 1));
    }
    else if(arr[i] == 2) {
        ret = 1+solve(i+1, 0);
        if(curr != 1)
            ret = min(ret, solve(i+1, 1));
    }
    else if(arr[i] == 1) {
        ret = 1+solve(i+1, 0);
        if(curr != 2)
            ret = min(ret, solve(i+1, 2));
    }
    else if(arr[i] == 0) {
        ret = min(solve(i+1, 0), solve(i+1, 0))+1;
    }

    return ret;
}

int main()
{
    cin >> n;
    arr = vector<int>(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof dp);

    cout << solve(0, 0) << endl;

    return 0;
}
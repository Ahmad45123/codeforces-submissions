#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int n;
vector<int> arr(n);

/*
 last = 0 -> did nothing
 last = 1 -> went gym
 last = 2 -> wrote contest
*/

int mem[101][3];

int solve(int i, int last) {
    if(i == n)
        return 0;

    if(mem[i][last] != -1)
        return mem[i][last];
    
    int ans = solve(i+1, 0);
    if((arr[i] == 1 || arr[i] == 3) && last != 2) {
        ans = max(ans, 1+solve(i+1, 2));
    }
    if((arr[i] == 2 || arr[i] == 3) && last != 1) {
        ans = max(ans, 1+solve(i+1, 1));
    }
    return mem[i][last] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n;
    arr = vector<int>(n);
    for(int &i : arr)
        cin >> i;
    memset(mem, -1, sizeof mem);
    cout << n-solve(0, 0) << "\n";

    return 0;
}
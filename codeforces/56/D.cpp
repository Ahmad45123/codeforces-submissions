#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s, t;
int dp[1001][1001];

ll solve(int i, int j) {
    if(i == s.size())
        return t.size()-j;
    if(j == t.size())
        return s.size()-i;
    if(~dp[i][j])
        return dp[i][j];
    
    if(s[i] == t[j]) {
        return (dp[i][j] = solve(i+1, j+1));
    } else {
        return (dp[i][j] = 1+min({solve(i+1, j), solve(i, j+1), solve(i+1, j+1)}));
    }
}

int delta = 0;
void insertChar(int idx, char c) {
    cout << "INSERT " << idx << " " << c << "\n";
}
void replaceChar(int idx, char c) {
    cout << "REPLACE " << idx << " " << c << "\n";
}
void deleteChar(int idx) {
    cout << "DELETE " << idx << "\n";
}

void backtrack(int i, int j) {
    if(i == s.size()) {
        for(int x = j; x < t.size(); x++) {
            insertChar(i+delta+1, t[x]);
            delta ++;
        }
        return;
    }

    if(j == t.size()) {
        for(int x = i; x < s.size(); x++) {
            deleteChar(x+delta+1);
            delta --;
        }
        return;
    }

    if(s[i] == t[j]) {
        backtrack(i+1, j+1);
    } else {
        ll replace = 1+solve(i+1, j+1);
        ll add = 1+solve(i, j+1);
        ll rem = 1+solve(i+1, j);
        if(solve(i, j) == replace) {
            replaceChar(i+delta+1, t[j]);
            backtrack(i+1, j+1);
        } else if(solve(i, j) == add) {
            insertChar(i+delta+1, t[j]);
            delta++;
            backtrack(i, j+1);
        } else if(solve(i, j) == rem) {
            deleteChar(i+delta+1);
            delta--;
            backtrack(i+1, j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    memset(dp, -1, sizeof dp);
    cin >> s >> t;
    cout << solve(0, 0) << "\n";
    backtrack(0, 0);
    
    return 0;
}
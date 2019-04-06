#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    int n; cin >> n;
    priority_queue<int> evens;
    priority_queue<int> odds;
    while(n--) {
        int t; cin >> t;
        if(t % 2 == 0)
            evens.push(t);
        else
            odds.push(t);
    }

    bool isEven = false;
    if(evens.size() > odds.size())
        isEven = true;

    while(true) {
        if(isEven && evens.size() != 0) {
            evens.pop();
            isEven = !isEven;
        }
        else if(!isEven && odds.size() != 0) {
            odds.pop();
            isEven = !isEven;
        }
        else
            break;
    }

    int curSum = 0;
    while(evens.size() > 0)
    {
        curSum += evens.top();
        evens.pop();
    }
    while(odds.size() > 0) {
        curSum += odds.top();
        odds.pop();
    }

    cout << curSum << '\n';

    int xyz; cin >> xyz; return 0;
}

/*
2 4 6 8
1 3 5
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, q; cin >> n >> q;
    set<int> oneBlocks;
    set<int> twoBlocks;
    int count = 0;
    while(q--) {
        int r, c; cin >> r >> c;

        if(r == 1) {
            if(oneBlocks.find(c) == oneBlocks.end()) {
                if(twoBlocks.find(c) != twoBlocks.end())
                    count ++;
                if(twoBlocks.find(c-1) != twoBlocks.end())
                    count ++;
                if(twoBlocks.find(c+1) != twoBlocks.end())
                    count ++;
                oneBlocks.insert(c);
            } else {
                if(twoBlocks.find(c) != twoBlocks.end())
                    count --;
                if(twoBlocks.find(c-1) != twoBlocks.end())
                    count --;
                if(twoBlocks.find(c+1) != twoBlocks.end())
                    count --;
                oneBlocks.erase(c);
            }
        } else if(r == 2) {
            if(twoBlocks.find(c) == twoBlocks.end()) {
                if(oneBlocks.find(c) != oneBlocks.end())
                    count ++;
                if(oneBlocks.find(c-1) != oneBlocks.end())
                    count ++;
                if(oneBlocks.find(c+1) != oneBlocks.end())
                    count ++;
                twoBlocks.insert(c);
            } else {
                if(oneBlocks.find(c) != oneBlocks.end())
                    count --;
                if(oneBlocks.find(c-1) != oneBlocks.end())
                    count --;
                if(oneBlocks.find(c+1) != oneBlocks.end())
                    count --;
                twoBlocks.erase(c);
            }
        }

        cout << (count == 0 ? "Yes\n" : "No\n");
    }
    
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int dist(int a, int b, int c) {
    return abs(a-b) + abs(a-c) + abs(b-c);
}

int main() {
    int q; cin >> q;
    while(q--) {
        int a, b, c; cin >> a >> b >> c;
        int ans = 2147483647;
        for(int x = -1; x <= 1; x++) {
            for(int y = -1; y <= 1; y++) {
                for(int z = -1; z <= 1; z++) {
                    ans = min(ans, dist(a+x, b+y, c+z));
                }
            }
        }
        cout << ans << "\r\n";
    }
    return 0;
}
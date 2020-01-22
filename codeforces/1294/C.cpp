#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> possibles;
        for(int i = 2; i <= ceil(sqrt(n)); i++) {
            if(n % i == 0)
                possibles.push_back(i);
        }

        int a1 = -1, a2 = -1, a3 = -1;

       //for each pair, find the 3 and check.
       for(int i = 0; i < possibles.size(); i++) {
           for(int j = i+1; j < possibles.size(); j++) {
               int third = n/(possibles[i]*possibles[j]);
               if(third*possibles[i]*possibles[j] == n && third != possibles[i] && third != possibles[j] && third != 1) {
                   a1 = possibles[i], a2 = possibles[j], a3 = third;
                   break;
               }
            }
            if(a1 != -1 && a2 != -1 && a3 != -1)
                break;
        }

        if(a1 == -1 || a2 == -1 || a3 == -1)
            cout << "NO\n";
        else {
            cout << "YES\n";
            cout << a1 << " " << a2 << " " << a3 << "\n";
        }
    }
    
 
    return 0;
}
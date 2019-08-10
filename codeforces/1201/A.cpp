#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n, m; cin >> n >> m;

    vector<string> anss(n);
    for(int i = 0; i < n; i++)
        cin >> anss[i];
    vector<int> scores(m);
    for(int i = 0; i < m; i++)
        cin >> scores[i];
    
    int totalScore = 0;
    for(int i = 0; i < m; i++) {
        int a = 0, b = 0, c = 0, d = 0, e = 0;
        for(int j = 0; j < n; j++) {
            switch(anss[j][i]) {
                case 'A': 
                    a++;
                break;
                case 'B': 
                    b++;
                break;
                case 'C': 
                    c++;
                break;
                case 'D': 
                    d++;
                break;
                case 'E': 
                    e++;
                break;
            }
        }

        totalScore += scores[i]*max(a, max(b, max(c, max(d, e))));
    }

    cout << totalScore;

    int xyz; cin >> xyz; return 0;
}
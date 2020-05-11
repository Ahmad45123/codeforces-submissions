#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int white = 0, black = 0;

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++) {
            char c; cin >> c;
            if(c == 'q') 
                white += 9;
            if(c == 'r') 
                white += 5;
            if(c == 'b') 
                white += 3;
            if(c == 'n') 
                white += 3;
            if(c == 'p') 
                white += 1;
            if(c == 'Q')
                black += 9;
            if(c == 'R')
                black += 5;
            if(c == 'B')
                black += 3;
            if(c == 'N')
                black += 3;
            if(c == 'P')
                black += 1;
        }
    
    if(white > black)
        cout << "Black\n";
    else if(black > white)
        cout << "White\n";
    else
        cout << "Draw\n";

    return 0;
}
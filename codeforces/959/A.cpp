#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    bool turn = false; //false => Mahmoud, true => ehab

    while(n > 0) {
        if(!turn)
        {
            //get next even number
            if(n % 2 == 0)
                n -= n;
            else{ 
                if(n-1 == 0)
                    break;
                n -= (n-1);
            }
            turn = !turn;
        }
        else {
            //get next odd number
            if(n % 2 != 0)
                n -= n;
            else{ 
                n -= (n-1);
            }
            turn = !turn;
        }
    }

    if(!turn)
        cout << "Ehab";
    else
        cout << "Mahmoud";

    int xyz; cin >> xyz; return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);

    int nboys; cin >> nboys;
    vector<int> boys(nboys);
    for(int i = 0; i < nboys; i++)
        cin >> boys[i];

    int ngirls; cin >> ngirls;
    vector<int> girls(ngirls);
    for(int i = 0; i < ngirls; i++)
        cin >> girls[i];

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    int currentBoy = 0;
    int currentGirl = 0;

    int pairs = 0;
    while(currentBoy < boys.size())
    {
        if(currentGirl >= girls.size())
            break;

        if(boys[currentBoy] - girls[currentGirl] == 1 || boys[currentBoy] - girls[currentGirl] == 0 || boys[currentBoy] - girls[currentGirl] == -1)
        {
            pairs++;
            currentGirl++;
            currentBoy++;
        }
        else if(boys[currentBoy] - girls[currentGirl] > 1)
        {
            currentGirl++;
        }
        else if(boys[currentBoy] - girls[currentGirl] < 0)
        {
            currentBoy++;
        }
    }

    cout << pairs;

    int xyz; cin >> xyz; return 0;
}
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);

    int n; cin >> n;

    queue<int> firstPlayer;
    queue<int> secondPlayer;

    //get first player cards.
    int k; cin >> k;
    for(int i = 0; i < k; i++)
    {
        int a; cin >> a;
        firstPlayer.push(a);
    }
    //get second player cards
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int a; cin >> a;
        secondPlayer.push(a);
    }

    unordered_map<string, int> hasBeenhere;

    //nfirst-nsecond-cardfirst-cardsecond

    int actions = 0;
    while(firstPlayer.empty() == false && secondPlayer.empty() == false)
    {
        actions++;
        int firstPlayerCard = firstPlayer.front(); 
        int secondPlayerCard = secondPlayer.front();

        //get the string
        string hash = to_string(firstPlayer.size()) + "-" + to_string(secondPlayer.size()) + "-" + to_string(firstPlayerCard) + "-" + to_string(secondPlayerCard);
        if(hasBeenhere[hash] == 5)
        {
            actions = -1;
            break;
        }
        hasBeenhere[hash]++;

        firstPlayer.pop();
        secondPlayer.pop();

        if(firstPlayerCard > secondPlayerCard)
        {
            firstPlayer.push(secondPlayerCard);
            firstPlayer.push(firstPlayerCard);
        }
        else {
            secondPlayer.push(firstPlayerCard);
            secondPlayer.push(secondPlayerCard);
        }
    }

    if(actions == -1)
        cout << -1;
    else
        if(firstPlayer.empty())
            cout << actions << " " << 2;
        else if(secondPlayer.empty())
            cout << actions << " " << 1;

    int xyz; cin >> xyz; return 0;
}
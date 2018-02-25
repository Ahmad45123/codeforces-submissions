#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool contains(vector<int> *list, int v)
{
	for (int i = 0; i < list->size(); i++)
	{
		if (list->at(i) == v)
		{
			return true;
		}
	}
	return false;
}

int main() {
	
	int people; cin >> people;
	vector<int> list(people);
	for (int i = 0; i < people; i++)
		cin >> list[i];

	std::sort(list.rbegin(), list.rend());

	int possibleWays = 0;
	vector<int> winners;

	for (int i = 0; i < people; i++)
	{
		if (list[i] != 0)
		{
			if (!contains(&winners, list[i]))
			{
				possibleWays++;
				winners.push_back(list[i]);
			}
		}
	}

	cout << possibleWays;
	return 0;
}

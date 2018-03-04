#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int start, end; cin >> start >> end;

	if (end < start)
	{
		int temp = end;
		end = start;
		start = temp;
	}

	int startStep = 1;
	int endStep = 1;

	int totalTireness = 0;

	while (start != end)
	{
		if (startStep < endStep)
		{
			totalTireness += startStep;
			startStep++;
			start++;
		}
		else {
			totalTireness += endStep;
			endStep++;
			end--;
		}
	}

	cout << totalTireness;

	int xyz; cin >> xyz;
    return 0;
}
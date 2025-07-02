#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	deque<pair<int, int>> dq; // { fruit , count }

	int fruitCount[10] = { 0, };

	int fruit;
	for (int i = 0; i < N; i++)
	{
		cin >> fruit;
		fruitCount[fruit]++;

		if (i == 0)
			dq.push_back({ fruit , 1 });
		else if (dq.back().first != fruit)
			dq.push_back({ fruit , 1 });
		else
			dq.back().second++;
	}

	int kind = 0;
	for (int i = 0; i < 10; i++)
	{
		if (fruitCount[i] > 0)
			kind++;
	}

	// sliding window
	deque<pair<int, int>> window(2);
	window[0] = dq[0];
	int answer = window[0].second;
	int cache = 0;

	for (int index = 1; index < dq.size(); index++)
	{
		int newFruit = dq[index].first;
		int newSize = dq[index].second;

		if (newFruit == window[0].first) // 겹침
		{
			cache = window[0].second;
			window[0].second += newSize;
			
			auto tmp = window[0];
			window[0] = window[1];
			window[1] = tmp;
		}
		else // 갱신 필요
		{
			if (window[1].first != 0)
			{
				window[0] = window[1];
				window[0].second -= cache;
				cache = 0;
			}

			window[1] = dq[index];
		}

		answer = max(answer, window[0].second + window[1].second);
	}

	cout << answer << "\n";

	return 0;
}
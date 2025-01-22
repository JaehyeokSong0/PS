#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	int answer = 0;
	int n;
	vector<pair<int, int>> wire;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int w1, w2;
		cin >> w1 >> w2;

		wire.push_back({ w1, w2 });
	}

	sort(wire.begin(), wire.end());

	// LIS
	vector<int> lis;
	for (int i = 0; i < n; i++)
	{
		lis.push_back(1);

		for (int j = 0; j < i; j++)
		{
			if (wire[i].second > wire[j].second)
				lis[i] = max(lis[j] + 1, lis[i]);
		}

		answer = max(lis[i], answer);
	}

	cout << n - answer << "\n";

	return 0;
}
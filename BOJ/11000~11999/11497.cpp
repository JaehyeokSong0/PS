#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMinDifficulty(vector<int>& logs, int size)
{
	vector<int> v;

	for (int i = 0; i < size; i += 2)
		v.push_back(logs[i]);

	if (size % 2 == 0)
	{
		for (int i = size - 1; i > 0; i -= 2)
			v.push_back(logs[i]);
	}
	else
	{
		for (int i = size - 2; i > 0; i -= 2)
			v.push_back(logs[i]);
	}


	int answer = -1;
	for (int i = 1; i < size; i++)
		answer = max(answer, abs(v[i] - v[i - 1]));

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;

		vector<int> logs(N);
		for (int i = 0; i < N; i++)
			cin >> logs[i];

		sort(logs.begin(), logs.end());

		cout << getMinDifficulty(logs, N) << "\n";
	}

	return 0;
}
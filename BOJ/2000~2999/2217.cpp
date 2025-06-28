#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> weights(N);
	for (int i = 0; i < N; i++)
	{
		cin >> weights[i];
	}

	sort(weights.begin(), weights.end(), greater<int>());
	int answer = 0;

	for (int k = 1; k <= N; k++)
	{
		answer = max(answer, weights[k - 1] * k);
	}

	cout << answer << "\n";

	return 0;
}
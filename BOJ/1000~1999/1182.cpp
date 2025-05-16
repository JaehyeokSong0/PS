#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getSum(int N, vector<int>& arr, vector<bool>& permutation)
{
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		if (permutation[i] == true)
			sum += arr[i];
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S, answer = 0;
	cin >> N >> S;

	vector<int> arr(N);
	vector<bool> permutation(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int size = 1; size <= N; size++)
	{
		for (int i = N - 1; i >= 0; i--)
			permutation[i] = (i >= N - size) ? true : false;

		do
		{
			if (getSum(N, arr, permutation) == S)
				answer++;
		} while (next_permutation(permutation.begin(), permutation.end()));
	}

	cout << answer << "\n";

	return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
using namespace std;

int getSour(vector<pair<int, int>>& tastes, vector<bool>& permutation)
{
	int length = tastes.size();
	int sour = 1;

	for (int i = 0; i < length; i++)
	{
		if (permutation[i] == true)
			sour *= tastes[i].first;
	}

	return sour;
}

int getBitter(vector<pair<int, int>>& tastes, vector<bool>& permutation)
{
	int length = tastes.size();
	int bitter = 0;

	for (int i = 0; i < length; i++)
	{
		if (permutation[i] == true)
			bitter += tastes[i].second;
	}

	return bitter;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, answer = 1e9;
	cin >> N;

	vector<pair<int, int>> tastes(N);
	vector<bool> permutation(N);

	int S, B;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> B;
		tastes[i] = { S,B };
	}

	// 조합 순열 구성
	for (int size = 1; size <= N; size++)
	{
		for (int i = N - 1; i >= 0; i--)
			permutation[i] = (i >= N - size) ? true : false;

		do
		{
			int sour = getSour(tastes, permutation);
			int bitter = getBitter(tastes, permutation);

			answer = min(answer, abs(sour - bitter));
		} while (next_permutation(permutation.begin(), permutation.end()));
	}

	cout << answer << "\n";

	return 0;
}
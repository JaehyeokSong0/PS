#include <iostream>
#include <vector>
using namespace std;

void flip(vector<vector<bool>>& coins, int x, int y)
{
	for (int i = x; i >= 0; i--)
	{
		for (int j = y; j >= 0; j--)
			coins[i][j] = !(coins[i][j]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Input
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> coins(N, vector<bool>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char ch;
			cin >> ch;

			coins[i][j] = (ch == '1');
		}
	}

	int answer = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = M - 1; j >= 0; j--)
		{
			if (coins[i][j] == true)
			{
				answer++;
				flip(coins, i, j);
			}
		}
	}

	cout << answer << "\n";

	return 0;
}
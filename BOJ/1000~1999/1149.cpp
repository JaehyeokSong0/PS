#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 1001

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, cost[3], memo[MAXSIZE][3] = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> cost[j];
		for (int j = 0; j < 3; j++)
			memo[i + 1][j] = min(memo[i][(j + 1) % 3], memo[i][(j + 2) % 3]) + cost[j];
	}

	cout << min(min(memo[n][0], memo[n][1]), memo[n][2]);

	return 0;
}
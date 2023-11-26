#include <iostream>
#include <algorithm>
using namespace std;

int w[101] = { 0, }, v[101] = { 0, };
int dp[101][100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (w[i] <= j)
				dp[i][j] = max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	cout << dp[n][k] << "\n";

	return 0;
}
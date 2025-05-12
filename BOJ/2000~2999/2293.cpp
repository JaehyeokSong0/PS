#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> coins(n, 0);
	for (int i = 0;i < n;i++)
	{
		cin >> coins[i];
	}
	sort(coins.begin(), coins.end());

	vector<int> dp(k + 1, 0);
	dp[0] = 1;

	for (int coin : coins)
	{
		for (int value = coin; value <= k; value++)
		{
			dp[value] += dp[value - coin];
		}
	}

	cout << dp[k] << "\n";
	return 0;
}
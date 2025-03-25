#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	set<int> coins;
	
	// dp[i] = i원을 만들기 위해 필요한 최소 동전의 개수
	vector<int> dp(k + 1, k + 1);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		int coinValue;
		cin >> coinValue;

		coins.insert(coinValue);
	}

	// 각 동전에 대해
	for (auto coin : coins)
	{
		// 각 금액에 대해
		for (int i = coin; i <= k; i++)
		{
			dp[i] = min(dp[i], dp[i - coin] + 1); // 현재 coin을 사용했을 때의 최솟값 계산
		}
	}

	if (dp[k] == k + 1)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << dp[k] << "\n";
	}

	return 0;
}
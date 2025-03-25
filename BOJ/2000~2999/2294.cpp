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
	
	// dp[i] = i���� ����� ���� �ʿ��� �ּ� ������ ����
	vector<int> dp(k + 1, k + 1);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		int coinValue;
		cin >> coinValue;

		coins.insert(coinValue);
	}

	// �� ������ ����
	for (auto coin : coins)
	{
		// �� �ݾ׿� ����
		for (int i = coin; i <= k; i++)
		{
			dp[i] = min(dp[i], dp[i - coin] + 1); // ���� coin�� ������� ���� �ּڰ� ���
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
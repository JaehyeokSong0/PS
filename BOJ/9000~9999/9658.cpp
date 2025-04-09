#include <iostream>
using namespace std;

bool dp[1001];

bool check(int n)
{
	if (n < 9)
		return dp[n];

	for (int i = 9; i <= n; i++)
	{
		if (dp[i - 4] && dp[i - 3] && dp[i - 1])
			dp[i] = false;
		else
			dp[i] = true;
	}

	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = dp[3] = dp[8] = false;
	dp[2] = dp[4] = dp[5] = dp[6] = dp[7] = true;
	int N;
	cin >> N;

	if (check(N) == true)
	{
		cout << "SK\n";
	}
	else
	{
		cout << "CY\n";
	}

	return 0;
}
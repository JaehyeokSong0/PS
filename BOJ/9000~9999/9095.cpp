#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;

	int n;
	int dp[11];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	while (T--)
	{
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}
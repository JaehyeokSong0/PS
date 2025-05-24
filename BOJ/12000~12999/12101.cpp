#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int dp[11];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	if (k > dp[n])
	{
		cout << "-1\n";
		return 0;
	}

	int remain = n;
	while (remain > 0)
	{
		// 1로 시작하는 경우
		if (k <= dp[remain - 1])
		{
			cout << "1";
			remain -= 1;
		}
		// 2로 시작하는 경우
		else if (remain >= 2 // 배열 인덱스 범위 처리
			&& k <= dp[remain - 1] + dp[remain - 2])
		{
			k -= dp[remain - 1]; // 1로 시작하는 경우의 수만큼 빼기

			cout << "2";
			remain -= 2;
		}
		else
		{
			// 1~2로 시작하는 경우의 수만큼 빼기
			k -= dp[remain - 1];
			if (remain >= 2)
				k -= dp[remain - 2];

			cout << "3";
			remain -= 3;
		}

		if (remain > 0)
			cout << "+";
		else
			cout << "\n";
	}

	return 0;
}
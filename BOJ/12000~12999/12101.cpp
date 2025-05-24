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
		// 1�� �����ϴ� ���
		if (k <= dp[remain - 1])
		{
			cout << "1";
			remain -= 1;
		}
		// 2�� �����ϴ� ���
		else if (remain >= 2 // �迭 �ε��� ���� ó��
			&& k <= dp[remain - 1] + dp[remain - 2])
		{
			k -= dp[remain - 1]; // 1�� �����ϴ� ����� ����ŭ ����

			cout << "2";
			remain -= 2;
		}
		else
		{
			// 1~2�� �����ϴ� ����� ����ŭ ����
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
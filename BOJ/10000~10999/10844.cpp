#include <iostream>
using namespace std;

#define MAXSIZE 101
#define DIVISOR 1000000000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long ret = 0, arr[MAXSIZE][10] = { 0, };
	cin >> n;

	for (int i = 1; i < 10; i++)
		arr[0][i] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				arr[i][j] = arr[i - 1][j + 1] % DIVISOR;
			else if (j == 9)
				arr[i][j] = arr[i - 1][j - 1] % DIVISOR;
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % DIVISOR;
		}
	}

	for (int i = 0; i < 10; i++)
		ret += arr[n - 1][i] % DIVISOR;
	cout << ret % DIVISOR;

	return 0;
}
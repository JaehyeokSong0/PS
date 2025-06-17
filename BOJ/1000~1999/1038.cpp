#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int combination(int n, int r, int index, ll& remain)
{
	if (n == 0)
		return (r == 0) ? 1 : 0;

	vector<bool> permutation(n);
	int count = 0;

	for (int i = n - 1; i >= 0; i--)
		permutation[i] = (i >= n - r) ? true : false;

	remain = 0;
	int digit = 0;
	do
	{
		count++;

		if (index-- <= 0 && remain == 0)
		{
			for (ll i = n - 1; i >= 0; i--)
			{
				if (permutation[i] == true)
					remain += (ll)pow(10, digit++) * (n - 1 - i);
			}
		}
	} while (next_permutation(permutation.begin(), permutation.end()));

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	if (N == 0)
	{
		cout << 0 << "\n";
		return 0;
	}

	vector<int> arr(N + 1);

	ll remain;
	for (int length = 1; length <= 10;length++) // 최대 감소하는 수 : 9876543210
	{
		for (ll firstNum = length - 1; firstNum <= 9; firstNum++)
		{
			int c = combination(firstNum, length - 1, N, remain);
			if (N - c < 0)
			{
				cout << firstNum * (ll)pow(10, length - 1) + remain;
				return 0;
			}
			else
			{
				N -= c;
			}
		}
	}

	cout << -1;

	return 0;
}
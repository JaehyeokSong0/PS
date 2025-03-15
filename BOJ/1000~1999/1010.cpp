#include <iostream>
#include <cmath>
using namespace std;

// nCr = n! / ((n-r)! r!)
long long getCombination(int n, int r)
{
	long long ret = 1;

	for (int i = 0; i < r; i++)
	{
		ret *= (n - i);
		ret /= (i + 1);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int M, N;
	for (int t = 0; t < T; t++)
	{
		cin >> M >> N;

		cout << getCombination(N, M) << "\n"; // 문제 조건 : (M >= N)
	}

	return 0;
}
#include <iostream>
using namespace std;

#define MAXSIZE 101

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long memo[MAXSIZE] = { 1,1,1,2,2 };
	int t, n;
	cin >> t;

	for (int i = 5; i < MAXSIZE; i++)
		memo[i] = memo[i - 1] + memo[i - 5];

	while (t--)
	{
		cin >> n;
		cout << memo[n - 1] << "\n";
	}

	return 0;
}
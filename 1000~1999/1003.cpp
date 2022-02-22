#include <iostream>
using namespace std;

#define MAXSIZE 41

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int memo[MAXSIZE] = { 0,1 };
	int t,n;
	cin >> t;

	for (int i = 2; i < MAXSIZE; i++)
		memo[i] = memo[i - 2] + memo[i - 1];

	while (t--)
	{
		cin >> n;
		if (n)
			cout << memo[n - 1] << " " << memo[n] << "\n";
		else
			cout << "1 0\n";
	}
}
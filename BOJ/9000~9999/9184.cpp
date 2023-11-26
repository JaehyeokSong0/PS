#include <iostream>
using namespace std;

#define MAXSIZE 101

int memo[MAXSIZE][MAXSIZE][MAXSIZE] = { 0, };

int func(int a, int b, int c)
{
	if ((a <= 0) || (b <= 0) || (c <= 0))
		return 1;
	else if (memo[a][b][c])
		return memo[a][b][c];
	else if ((a > 20) || (b > 20) || (c > 20))
		memo[a][b][c] = func(20, 20, 20);
	else if ((a < b) && (b < c))
		memo[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
	else
		memo[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
	return memo[a][b][c];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if ((a == -1) && (b == -1) && (c == -1))
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << func(a, b, c) << "\n";
	}

	return 0;
}
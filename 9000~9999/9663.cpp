#include <iostream>
#include <cmath>
using namespace std;

#define MAXSIZE 16

int n;
int ret = 0;
int col[MAXSIZE] = { 0, };

bool promising(int i)
{
	for (int j = 0; j < i; j++)
	{
		if ((col[i] == col[j]) || (abs(col[i] - col[j]) == i - j))
			return false;
	}
	return true;
}

void queen(int i)
{
	if (promising(i - 1))
	{
		if (i == n)
		{
			ret++;
			return;
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				col[i] = j;
				queen(i + 1);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	queen(0);

	cout << ret << endl;

	return 0;
}
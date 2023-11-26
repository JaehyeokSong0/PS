#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXSIZE 21

int n;
int matrix[MAXSIZE][MAXSIZE] = { 0, };
bool check[MAXSIZE] = { false, };
int ret = 201;

void dfs(int x, int y)
{
	int startStat = 0, linkStat = 0; // 각 팀의 능력치
	if (x == n / 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (check[i] && check[j])
					startStat += (matrix[i][j] + matrix[j][i]);
				else if (!check[i] && !check[j])
					linkStat += (matrix[i][j] + matrix[j][i]);
			}
		}
		ret = min(ret, abs(startStat - linkStat));
	}
	else
	{
		for (int i = y; i < n; i++)
		{
			if (!check[i])
			{
				check[i] = true;
				dfs(x + 1, i + 1);
				check[i] = false;
			}

		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	dfs(0, 1);

	cout << ret << endl;

	return 0;
}
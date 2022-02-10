#include <iostream>
using namespace std;

int matrix[9][9];
int found = false;

void getMatrix()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cin >> matrix[i][j];
	}
}

void printMatrix()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
}

bool promising(int i, int j, int num)
{
	for (int n = 0; n < 9; n++)
	{
		if ((j != n) && (num == matrix[i][n])) // 가로줄 검사
			return false;
		if ((i != n) && (num == matrix[n][j])) // 세로줄 검사
			return false;
		if (num == matrix[i / 3 * 3 + n / 3][j / 3 * 3 + n % 3]) // 3x3 박스 검사
			return false;
	}
	return true;
}

void solve(int depth)
{
	if (found)
		return;
	if (depth == 81)
	{
		printMatrix();
		found = true;
		return;
	}
	int i = depth / 9;
	int j = depth % 9;
	if (matrix[i][j] == 0)
	{
		bool flag = false;
		for (int k = 1; k <= 9; k++)
		{
			if (promising(i, j, k))
			{
				matrix[i][j] = k;
				solve(depth + 1);
				matrix[i][j] = 0;
			}
		}
	}
	else
		solve(depth + 1);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	getMatrix();
	solve(0);

	return 0;
}
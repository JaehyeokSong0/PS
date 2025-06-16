#include <iostream>
#include <vector>
using namespace std;

void inputMatrix(int rowSize, int colSize, vector<vector<bool>>& matrix)
{
	char ch;
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			cin >> ch;
			matrix[i][j] = (bool)(ch - '0');
		}
	}
}

void flip(int row, int col, vector<vector<bool>>& matrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[row + i][col + j] = matrix[row + i][col + j] ^ true;
		}
	}
}

bool check(int rowSize, int colSize, vector<vector<bool>>& matrix)
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			if (matrix[i][j] == true)
				return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int answer = 0;
	

	vector<vector<bool>> A(N, vector<bool>(M));
	vector<vector<bool>> B(N, vector<bool>(M));
	vector<vector<bool>> diff(N, vector<bool>(M, false));

	inputMatrix(N, M, A);
	inputMatrix(N, M, B);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] != B[i][j])
				diff[i][j] = true;
		}
	}

	if (check(N, M, diff) == true)
	{
		cout << 0 << "\n";
		return 0;
	}

	if (N < 3 || M < 3)
	{
		cout << -1 << "\n";
		return 0;
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (diff[i][j] == 1)
			{
				answer++;
				flip(i, j, diff);
			}
		}
	}

	if (check(N, M, diff) == true)
		cout << answer << "\n";
	else
		cout << -1 << "\n";

	return 0;
}
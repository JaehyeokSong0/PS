#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 21

int r, c;
int ret = 0;
char matrix[MAXSIZE][MAXSIZE];
bool alphabet[26] = { false, };	// 'A' ~ 'Z'의 등장 여부

bool promising(int i,int j)
{
	if ((!((0 <= i) && (i < r))) || (!((0 <= j) && (j < c)))) // matrix 범위 벗어난 경우
		return false;
	else if (alphabet[matrix[i][j] - 'A']) // 이미 지나온 알파벳인 경우
		return false;
	else
		return true;
}

void solve(int i, int j, int depth)
{
	ret = max(ret, depth);
	if (promising(i, j - 1)) // 상
	{
		alphabet[matrix[i][j - 1] - 'A'] = true;
		solve(i, j - 1, depth + 1);
		alphabet[matrix[i][j - 1] - 'A'] = false;
	}
	if (promising(i, j + 1)) // 하
	{
		alphabet[matrix[i][j + 1] - 'A'] = true;
		solve(i, j + 1, depth + 1);
		alphabet[matrix[i][j + 1] - 'A'] = false;
	}
	if (promising(i - 1, j)) // 좌
	{
		alphabet[matrix[i - 1][j] - 'A'] = true;
		solve(i - 1, j, depth + 1);
		alphabet[matrix[i - 1][j] - 'A'] = false;
	}
	if (promising(i + 1, j)) // 우
	{
		alphabet[matrix[i + 1][j] - 'A'] = true;
		solve(i + 1, j, depth + 1);
		alphabet[matrix[i + 1][j] - 'A'] = false;
	}
	return;
}

void getMatrix()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cin >> matrix[i][j];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> r >> c;
	getMatrix();

	alphabet[matrix[0][0] - 'A'] = true;
	solve(0,0,1);

	cout << ret << "\n";

	return 0;
}
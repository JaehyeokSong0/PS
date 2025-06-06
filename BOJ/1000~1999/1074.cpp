#include <iostream>
#include <cmath>
using namespace std;

int solve(int size, int row, int col)
{
	int answer = 0;

	if (size == 1)
	{
		if (row == 0 && col == 0)
			return 0;
		else if (row == 0 && col == 1)
			return 1;
		else if (row == 1 && col == 0)
			return 2;
		else if (row == 1 && col == 1)
			return 3;
	}

	int totalSize = (int)pow(2, size);
	int halfSize = totalSize / 2;

	// 사분면 찾기
	if (row < halfSize && col >= halfSize) // 1사분면 (우상)
		answer += halfSize * halfSize + solve(size - 1, row, col - halfSize);
	else if (row < halfSize && col < halfSize) // 2사분면 (좌상)
		answer += solve(size - 1, row, col);
	else if (row >= halfSize && col < halfSize) // 3사분면 (좌하)
		answer += halfSize * halfSize * 2 + solve(size - 1, row - halfSize, col);
	else if (row >= halfSize && col >= halfSize) // 4사분면 (우하)
		answer += halfSize * halfSize * 3 + solve(size - 1, row - halfSize, col - halfSize);

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, r, c;
	cin >> N >> r >> c;

	cout << solve(N, r, c) << "\n";

	return 0;
}
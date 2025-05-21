#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix, int N, int M, int R)
{
	int maxOffset = min(N, M) / 2;
	vector<queue<int>> offsetQueue(maxOffset);

	// 중심에서 먼 층부터 Queue에 삽입
	for (int offset = 0; offset < maxOffset; offset++)
	{
		// Top - Left : Initial Point
		// Top
		for (int i = offset; i < M - offset - 1; i++)
			offsetQueue[offset].push(matrix[offset][i]);
		// Right 
		for (int i = offset; i < N - offset - 1; i++)
			offsetQueue[offset].push(matrix[i][M - offset - 1]);
		// Bottom  
		for (int i = M - offset - 1; i > offset; i--)
			offsetQueue[offset].push(matrix[N - offset - 1][i]);
		// Left 
		for (int i = N - offset - 1; i > offset; i--)
			offsetQueue[offset].push(matrix[i][offset]);
	}

	// R 만큼 회전
	for (int i = 0; i < R; i++)
	{
		for (queue<int>& q : offsetQueue)
		{
			q.push(q.front());
			q.pop();
		}
	}

	// OffsetQueue에 저장된 정보를 matrix에 대입
	for (int offset = 0; offset < maxOffset; offset++)
	{
		// Top - Left : Initial Point
		// Top
		for (int i = offset; i < M - offset - 1; i++)
		{
			matrix[offset][i] = offsetQueue[offset].front();
			offsetQueue[offset].pop();
		}
		// Right 
		for (int i = offset; i < N - offset - 1; i++)
		{
			matrix[i][M - offset - 1] = offsetQueue[offset].front();
			offsetQueue[offset].pop();
		}
		// Bottom  
		for (int i = M - offset - 1; i > offset; i--)
		{
			matrix[N - offset - 1][i] = offsetQueue[offset].front();
			offsetQueue[offset].pop();
		}
		// Left 
		for (int i = N - offset - 1; i > offset; i--)
		{
			matrix[i][offset] = offsetQueue[offset].front();
			offsetQueue[offset].pop();
		}
	}
}

void printMatrix(vector<vector<int>>& matrix, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;

	vector<vector<int>> matrix(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> matrix[i][j];
		}
	}

	rotateMatrix(matrix, N, M, R);
	printMatrix(matrix, N, M);

	return 0;
}
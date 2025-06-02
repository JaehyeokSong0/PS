#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 상 우 하 좌
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

bool isValid(int N, int row, int col)
{
	return (0 <= row) && (row < N)
		&& (0 <= col) && (col < N);
}

int getLikes(int N, int row, int col, vector<vector<int>>& seats, vector<int>& likes)
{
	int answer = 0;

	for (int i = 0; i < 4; i++)
	{
		int newRow = row + dy[i];
		int newCol = col + dx[i];

		if (isValid(N, newRow, newCol))
		{
			int friendIdx = seats[newRow][newCol];
			if (friendIdx != 0)
			{
				auto it = find(likes.begin(), likes.end(), friendIdx);
				if (it != likes.end())
					answer++;
			}
		}
	}

	return answer;
}

int getTotalLikes(int N, vector<vector<int>>& seats, vector<vector<int>>& likes)
{
	int answer = 0;

	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < N; j++)
		{
			switch (getLikes(N, i, j, seats, likes[seats[i][j]]))
			{
			case 1:
			{
				answer += 1;
			}
			break;
			case 2:
			{
				answer += 10;
			}
			break;
			case 3:
			{
				answer += 100;
			}
			break;
			case 4:
			{
				answer += 1000;
			}
			break;
			}
		}
	}

	return answer;
}

int getSpace(int N, int row, int col, vector<vector<int>>& seats)
{
	int answer = 0;

	for (int i = 0; i < 4; i++)
	{
		int newRow = row + dy[i];
		int newCol = col + dx[i];

		if (isValid(N, newRow, newCol))
		{
			if (seats[newRow][newCol] == 0)
				answer++;
		}
	}

	return answer;
}

void assignSeat(int studentIndex, int N, vector<vector<int>>& seats, vector<vector<int>>& likes)
{
	int mostLikes = 0; // Case 1
	int mostSpaces = 0; // Case 2 

	int finalRow = -1, finalCol = -1;

	// Case 1 : 비어있는 칸 중 좋아하는 학생이 인접한 칸에 가장 많음
	// Case 2 : 인접한 칸 중 비어있는 칸이 가장 많은 칸
	// Case 3 : 행의 번호가 가장 작은 칸 => 열의 번호가 가장 작은 칸
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 이미 다른 사람이 앉아있으면 continue
			if (seats[i][j] != 0)
				continue;

			int like = getLikes(N, i, j, seats, likes[studentIndex]); // Case 1
			if (mostLikes < like) // Case 1 만족 가능
			{
				mostLikes = like;
				mostSpaces = getSpace(N, i, j, seats);

				finalRow = i;
				finalCol = j;
			}
			else if (mostLikes == like) // Case 1 만족 실패
			{
				// Case 2
				int space = getSpace(N, i, j, seats);
				if (mostSpaces < space) // Case 2 만족 가능
				{
					mostSpaces = space;

					finalRow = i;
					finalCol = j;
				}
				else if (mostSpaces == space) // Case 2 만족 실패
				{
					// Case 3
					if (finalRow > i)
					{
						finalRow = i;
						finalCol = j;
					}
					else if (finalRow == i)
					{
						finalCol = min(finalCol, j);
					}

					if (finalRow == -1 || finalCol == -1)
					{
						finalRow = i;
						finalCol = j;
					}
				}
			}
		}
	}

	seats[finalRow][finalCol] = studentIndex;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, answer = 0;
	cin >> N;

	vector<vector<int>> likes(N * N + 1, vector<int>(4));
	vector<vector<int>> seats(N, vector<int>(N, 0));
	vector<int> order(N * N);
	// Input
	for (int i = 0; i < N * N; i++)
	{
		int studentIndex;
		cin >> studentIndex;

		cin >> likes[studentIndex][0] >> likes[studentIndex][1]
			>> likes[studentIndex][2] >> likes[studentIndex][3];

		order[i] = studentIndex;
	}

	for (int i = 0; i < N * N;i++)
		assignSeat(order[i], N, seats, likes);

	cout << getTotalLikes(N, seats, likes);

	return 0;
}

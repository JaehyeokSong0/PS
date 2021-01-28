#include <iostream>
#include <queue>
using namespace std;

#define MAXSIZE 100+1
int maze[MAXSIZE][MAXSIZE];
int n, m; //n:높이, m:너비

bool checkAvilableRange(int x, int y) //(x,y)가 (1,1) ~ (n,m) 범위를 벗어나는지 확인
{
	if (((x >= 1) && (x <= n)) && ((y >= 1) && (y <= m)))
		return true;
	else
		return false;
}

int main()
{
	cin >> n >> m;

	//미로 구조 입력
	for (int row = 1; row <= n; row++)
	{
		for (int col = 1; col <= m; col++)
			scanf("%1d", &maze[row][col]);
	}

	//bfs
	int distance[MAXSIZE][MAXSIZE] = { 0, }; //(1,1)로부터의 거리를 저장하는 배열
	distance[1][1] = 1;
	queue <pair<int, int>> q;
	q.push(make_pair(1, 1));
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 }; //순서대로 상 우 하 좌 (시계방향)
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		if ((x == n) && (y == m)) //(n,m)에 도착
			break;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			//이동가능한지 확인 할 인접좌표
			int checkX = x + dx[i];
			int checkY = y + dy[i];
			//확인할 좌표가 maze배열을 벗어나는지 확인
			if (checkAvilableRange(checkX, checkY))
			{
				if (maze[checkX][checkY] == 1 && distance[checkX][checkY] == 0) //이동가능하며 아직 확인하지 않은 칸에 대해
				{
					q.push(make_pair(checkX, checkY));
					distance[checkX][checkY] = distance[x][y] + 1;
				}
			}
		}
	}
	cout << distance[n][m];
	return 0;
}
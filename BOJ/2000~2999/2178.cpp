#include <iostream>
#include <queue>
using namespace std;

#define MAXSIZE 100+1
int maze[MAXSIZE][MAXSIZE];
int n, m; //n:����, m:�ʺ�

bool checkAvailableRange(int x, int y) //(x,y)�� (1,1) ~ (n,m) ������ ������� Ȯ��
{
	if (((x >= 1) && (x <= n)) && ((y >= 1) && (y <= m)))
		return true;
	else
		return false;
}

int main()
{
	cin >> n >> m;

	//�̷� ���� �Է�
	for (int row = 1; row <= n; row++)
	{
		for (int col = 1; col <= m; col++)
			scanf("%1d", &maze[row][col]);
	}

	//bfs
	int distance[MAXSIZE][MAXSIZE] = { 0, }; //(1,1)�κ����� �Ÿ��� �����ϴ� �迭
	distance[1][1] = 1;
	queue <pair<int, int>> q;
	q.push(make_pair(1, 1));
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 }; //������� �� �� �� �� (�ð����)
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		if ((x == n) && (y == m)) //(n,m)�� ����
			break;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			//�̵��������� Ȯ�� �� ������ǥ
			int checkX = x + dx[i];
			int checkY = y + dy[i];
			//Ȯ���� ��ǥ�� maze�迭�� ������� Ȯ��
			if (checkAvailableRange(checkX, checkY))
			{
				if (maze[checkX][checkY] == 1 && distance[checkX][checkY] == 0) //�̵������ϸ� ���� Ȯ������ ���� ĭ�� ����
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
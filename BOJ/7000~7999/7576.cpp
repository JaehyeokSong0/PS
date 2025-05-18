#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

// �� �� �� ��
short dx[4] = { 1,0,-1,0 };
short dy[4] = { 0,1,0,-1 };

bool isValid(short x, short y, short M, short N)
{
	return (0 <= x) && (x < N) && (0 <= y) && (y < M);
}

void bfs(vector<vector<short>>& tomato, queue<pair<short, short>>& q, short M, short N)
{
	queue<pair<short, short>> tmpQ;

	while (!q.empty())
	{
		auto coord = q.front();
		q.pop();

		for (short i = 0; i < 4;i++)
		{
			short toX = coord.first + dx[i];
			short toY = coord.second + dy[i];

			if (isValid(toX, toY, M, N) == true)
			{
				if (tomato[toX][toY] == 0)
				{
					tomato[toX][toY] = 1;
					tmpQ.push({ toX, toY });
				}
			}
		}
	}

	q = tmpQ;

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	short M, N;
	cin >> M >> N;

	vector<vector<short>> tomato(N, vector<short>(M));
	queue<pair<short, short>> q;
	short count = 0; // �������Ѿ� �� �丶��(input : 0) ����
	for (short i = 0; i < N;i++)
	{
		for (short j = 0; j < M; j++)
		{
			cin >> tomato[i][j];

			if (tomato[i][j] == 1)
				q.push({ i,j });
			else if (tomato[i][j] == 0)
				count++;
		}
	}

	short answer = -1;
	if (q.size() == M * N) // ��� �丶�䰡 ó������ �;��ִ� ����
	{
		answer = 0;
	}
	else
	{
		if (!q.empty())
			count += q.size(); 

		while (!q.empty())
		{
			count -= q.size();
			bfs(tomato, q, M, N);
			answer++;
		}
	}

	if (count > 0)
		answer = -1;

	cout << answer << "\n";
	return 0;
}
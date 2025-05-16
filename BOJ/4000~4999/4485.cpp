#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ©Л го аб ╩С
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isValid(int x, int y, int N)
{
	return (0 <= x) && (x < N) && (0 <= y) && (y < N);
}

void searchCave(int N, vector<vector<int>>& cave, vector<vector<int>>& costs)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	// {cost, {x, y}}
	pq.push({ costs[0][0], {0,0} });

	while (!pq.empty())
	{
		auto cost = pq.top().first;
		auto coord = pq.top().second;
		int x = coord.first;
		int y = coord.second;

		pq.pop();

		if (cost > costs[x][y])
			continue;

		if ((x == N - 1) && (y == N - 1))
			return;

		for (int i = 0; i < 4; i++)
		{
			int toX = x + dx[i];
			int toY = y + dy[i];

			if (isValid(toX, toY, N))
			{
				if (costs[toX][toY] > costs[x][y] + cave[toX][toY])
				{
					costs[toX][toY] = costs[x][y] + cave[toX][toY];
					pq.push({ costs[toX][toY], {toX, toY} });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, prob = 1;
	while (cin >> N)
	{
		if (N == 0)
			break;

		vector<vector<int>> cave(N, vector<int>(N));
		vector<vector<int>> costs(N, vector<int>(N, 1e9));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N;j++)
				cin >> cave[i][j];
		}

		costs[0][0] = cave[0][0];
		searchCave(N, cave, costs);

		cout << "Problem " << prob++ << ": " << costs[N - 1][N - 1] << "\n";
	}
}
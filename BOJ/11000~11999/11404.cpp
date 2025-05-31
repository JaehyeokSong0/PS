#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9

void floydWarshall(vector<vector<int>>& dist, int size)
{
	for (int via = 1; via <= size; via++)
	{
		for (int from = 1; from <= size; from++)
		{
			for (int to = 1; to <= size; to++)
			{
				dist[from][to] = min(dist[from][to], dist[from][via] + dist[via][to]);
			}
		}
	}
}

void printDistance(vector<vector<int>>& dist, int size)
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (dist[i][j] != INF)
				cout << dist[i][j] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	int a, b, c;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}

	floydWarshall(dist, n);
	printDistance(dist, n);

	return 0;
}
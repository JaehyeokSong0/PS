#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E, K;
	cin >> V >> E >> K;

	vector<vector<pair<int, int>>> graph(V + 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<bool> visited(V + 1, false);
	vector<int> minDist(V + 1, INT_MAX);

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	minDist[K] = 0;
	pq.push({ 0, K });

	while (!pq.empty())
	{
		auto current = pq.top();
		pq.pop();

		if (visited[current.second] == true)
			continue;

		for (auto next : graph[current.second])
		{
			if (visited[next.first] == false && minDist[current.second] + next.second < minDist[next.first])
			{
				minDist[next.first] = minDist[current.second] + next.second;
				pq.push({ minDist[next.first], next.first });
			}
		}

		visited[current.second] = true;
	}

	for (int i = 1; i <= V; i++)
	{
		if (minDist[i] != INT_MAX)
			cout << minDist[i] << "\n";
		else
			cout << "INF\n";
	}

	return 0;
}
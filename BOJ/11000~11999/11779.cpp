#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_COST 100000001 // 100000 * 1000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n + 1); // graph[src] = { dst, cost }
	vector<int> dist(n + 1, MAX_COST);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // { dist, node }
	vector<int> prev(n + 1);

	int src, dst, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> src >> dst >> cost;

		graph[src].push_back({ dst, cost });
	}

	int start, end;
	cin >> start >> end;

	// Dijkstra
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		if (curr.first > dist[curr.second]) // A // THIS
			continue;

		// 현재 node에서 갈 수 있는 node
		for (auto& next : graph[curr.second])
		{
			if (dist[curr.second] + next.second < dist[next.first]) // 현재 노드 거리 + 다음 노드 cost < 저장된 다음 노드 거리
			{
				prev[next.first] = curr.second;

				dist[next.first] = dist[curr.second] + next.second;
				pq.push({ dist[next.first], next.first });
			}
		}
	}

	// 출발 도시에서 도착 도시까지 최소 비용
	cout << dist[end] << "\n";

	// 최소 비용 경로의 도시 개수 & 경로
	int node = end;
	int count = 0;
	vector<int> routes;
	while (node != start)
	{
		routes.push_back(node);
		node = prev[node];
		count++;
	}
	routes.push_back(start);
	count++;

	cout << count << "\n";;

	for (int i = routes.size() - 1; i >= 0; i--)
	{
		cout << routes[i] << " ";
	}
	cout << "\n";

	return 0;
}
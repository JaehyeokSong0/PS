#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int find(int x, vector<int>& parent)
{
	int root = x;

	// 탐색
	while (root != parent[root])
	{
		root = parent[root];
	}

	// 압축
	while (x != root)
	{
		int prev = x;
		x = parent[x];
		parent[prev] = root;
	}

	return root;
}

void makeUnion(int x, int y, vector<int>& parent)
{
	x = find(x, parent);
	y = find(y, parent);

	// 작은 수를 union 대표로 설정
	if (x > y)
		parent[x] = y;
	else
		parent[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<pair<int, pair<int, int>>> graph; // {cost, {src, dst}}
	vector<int> parent(N + 1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	int A, B, C;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;

		graph.push_back({ C,{ A,B } });
	}

	sort(graph.begin(), graph.end());

	vector<pair<int, pair<int, int>>> roads;
	for (auto& data : graph)
	{
		int cost = data.first;
		auto& edge = data.second;

		if (find(edge.first, parent) != find(edge.second, parent))
		{
			makeUnion(edge.first, edge.second, parent);
			roads.push_back(data);
		}
	}

	int maxCost = -1;
	int sumCost = 0;
	for (auto& road : roads)
	{
		int cost = road.first;
		auto& edge = road.second;

		if (maxCost < cost)	
			maxCost = cost;

		sumCost += cost;
	}

	cout << sumCost - maxCost << "\n";

	return 0;
}
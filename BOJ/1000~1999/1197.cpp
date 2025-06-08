#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

// 탐색 및 압축
int find(int x, vector<int>& root)
{
	if (x == root[x])
		return x;

	int parent = root[x];
	while (parent != root[parent])
	{
		root[x] = parent;
		parent = root[parent];
	}

	return parent;
}

// 더 낮은 인덱스의 정점을 root로 설정
void makeUnion(int x, int y, vector<int>& root)
{
	int larger = (x >= y) ? x : y;
	int smaller = (x < y) ? x : y;

	root[find(larger, root)] = find(smaller, root);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<tuple<int, int, int>> edges(E); // { cost, from, to }
	vector<int> root(V + 1);
	for (int i = 1; i <= V; i++)
		root[i] = i;

	int A, B, C;
	for (int i = 0;i < E;i++)
	{
		cin >> A >> B >> C;
		edges[i] = { C, A, B };
	}

	sort(edges.begin(), edges.end());

	int answer = 0;

	for (auto& edge : edges)
	{
		int cost = get<0>(edge);
		int from = get<1>(edge);
		int to = get<2>(edge);

		if (find(from, root) != find(to, root))
		{
			makeUnion(from, to, root);
			answer += cost;
		}
	}

	cout << answer << "\n";

	return 0;
}
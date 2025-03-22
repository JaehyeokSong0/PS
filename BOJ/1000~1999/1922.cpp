#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int find(vector<int>& root, int index)
{
	if (root[index] == index)
	{
		return index;
	}
	else
	{
		return find(root, root[index]);
	}
}

void makeUnion(vector<int>& root, int x, int y)
{
	x = find(root, x);
	y = find(root, y);

	root[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> root(N + 1);
	for (int i = 1; i <= N; i++)
	{
		root[i] = i;
	}

	vector<tuple<int, int, int>> costs;

	for (int i = 0; i < M; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;

		costs.push_back({ cost, x, y });
	}

	int answer = 0;
	int connected = 1;
	sort(costs.begin(), costs.end());

	for (auto element : costs)
	{
		if (find(root, get<1>(element)) != find(root, get<2>(element)))
		{
			makeUnion(root, get<1>(element), get<2>(element));
			answer += get<0>(element);
			connected++;
		}

		if (connected == N)
		{
			cout << answer << "\n";
			break;
		}
	}

	return 0;
}
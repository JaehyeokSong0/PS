#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int indegree[32002];
vector<int> graph[32002];
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int A, B;
	for (int m = 1; m <= M; m++)
	{
		cin >> A >> B;
		graph[A].push_back(B);
		indegree[B]++;
	}

	for (int n = 1; n <= N; n++)
	{
		if (indegree[n] == 0)
			q.push(n);
	}

	while (!q.empty())
	{
		int f = q.front();
		q.pop();

		cout << f << " ";
		for (auto out : graph[f])
		{
			indegree[out]--;
			if (indegree[out] == 0)
				q.push(out);
		}
	}

	return 0;
}
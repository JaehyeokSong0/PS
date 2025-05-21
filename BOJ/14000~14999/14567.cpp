#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	vector<int> indegrees(N + 1, 0);
	vector<int> answer(N + 1, 0);
	queue<int> q;

	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		graph[A].push_back(B);
		indegrees[B]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (indegrees[i] == 0)
			q.push(i);
	}

	int day = 1;
	int qCount = q.size();
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		if (indegrees[node] == 0)
			answer[node] = day;

		for (auto out : graph[node])
		{
			indegrees[out]--;

			if (indegrees[out] == 0)
			{
				q.push(out);
			}
		}

		qCount--;
		if (qCount == 0)
		{
			day++;
			qCount = q.size();
		}
	}

	for (int i = 1; i <= N; i++)
		cout << answer[i] << " ";
	cout << "\n";

	return 0;
}
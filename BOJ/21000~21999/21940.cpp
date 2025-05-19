#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9

void floydWarshall(vector<vector<int>>& dist, int N)
{
	for (int via = 1; via <= N; via++)
	{
		for (int from = 1; from <= N; from++)
		{
			for (int to = 1; to <= N; to++)
			{
				if ((dist[from][to] > dist[from][via] + dist[via][to])
					&& (dist[from][via] != INF && dist[via][to] != INF))
					dist[from][to] = dist[from][via] + dist[via][to];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M;
	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		cin >> dist[A][B];
	}

	for (int i = 1; i <= M; i++)
		dist[i][i] = 0;

	floydWarshall(dist, N);

	cin >> K;
	vector<int> start(K);
	for (int i = 0; i < K; i++)
	{
		cin >> start[i];
	}

	// 조건 만족하는 도시 찾기
	vector<int> answer;
	int minOfMax = INF;

	// 각 도시에 대해
	for (int i = 1; i <= N; i++)
	{
		bool canReach = true; // 모든 친구가 도달 가능한지
		for (int st : start)
		{
			if (dist[st][i] == INF || dist[i][st] == INF)
			{
				canReach = false;
				break;
			}
		}
		
		if (!canReach)
			continue;

		int maxTime = -1;
		for (int st : start)
			maxTime = max(maxTime, dist[st][i] + dist[i][st]);
		
		if (minOfMax > maxTime)
		{
			answer.clear();
			minOfMax = maxTime;
			answer.push_back(i);
		}
		else if (minOfMax == maxTime)
		{
			answer.push_back(i);
		}

	}

	for (auto ans : answer)
	{
		cout << ans << " ";
	}
	cout << "\n";

	return 0;
}
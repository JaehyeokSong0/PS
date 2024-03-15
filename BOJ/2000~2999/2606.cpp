#include <iostream>
#include <queue>
using namespace std;

bool visited[101];
queue<int> edge[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	int V, E;
	cin >> V >> E;
	
	int i, j;
	for (int e = 0; e < E; e++)
	{
		cin >> i >> j;
		edge[i].push(j);
		edge[j].push(i);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;

	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		
		int qSize = edge[node].size();
		for (int i = 0; i < qSize; i++)
		{
			int v = edge[node].front();
			edge[node].pop();
			
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
				answer++;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_SIZE 501

int cost[MAX_SIZE];
int outDegree[MAX_SIZE];
vector<int> out[MAX_SIZE];
vector<int> in[MAX_SIZE];
int ret[MAX_SIZE] = { 0, };

void calc(int nodeCnt)
{
	queue<int> q;

	for (int i = 1; i <= nodeCnt; i++)
	{
		if (outDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int index = q.front();
		q.pop();

		int maxCost = 0;
		for (auto& o : out[index])
		{
			if (ret[o] != 0) // 확정된 cost라면
			{
				maxCost = max(maxCost, ret[o]);
			}
		}

		ret[index] = cost[index] + maxCost;

		for (auto& i : in[index])
		{
			outDegree[i]--;
			if (outDegree[i] == 0)
			{
				q.push(i);
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1;i <= N; i++)
	{
		int input;
		cin >> input;
		cost[i] = input;
		outDegree[i] = 0;

		while (cin >> input)
		{
			if (input == -1)
				break;

			out[i].push_back(input);
			outDegree[i]++;

			in[input].push_back(i);
		}
	}

	calc(N);

	for (int i = 1; i <= N; i++)
	{
		cout << ret[i] << "\n";
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

typedef priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> MinHeap;

void solve(int K, MinHeap& pq, vector<int>& minTime)
{
	int timestamp = pq.top().first;
	int position = pq.top().second;
	pq.pop();

	if (minTime[position] > timestamp)
		minTime[position] = timestamp;
	else
		return;

	if (position == K)
		minTime[position] = min(minTime[position], timestamp);

	// walk
	if (position >= 1 && minTime[position - 1] > timestamp + 1)
		pq.push({ timestamp + 1 , position - 1 });
	if (position < 100000 && position < K && minTime[position + 1] > timestamp + 1)
		pq.push({ timestamp + 1 , position + 1 });

	// teleport
	if (position * 2 <= 100000 && position < K && minTime[position * 2] > timestamp)
		pq.push({ timestamp , position * 2 });
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	MinHeap pq;
	vector<int> minTime(100001, 2e9); // 좌표별 도달한 최저시각

	pq.push({ 0, N });

	while (!pq.empty())
	{
		solve(K, pq, minTime);
	}

	cout << minTime[K] << "\n";

	return 0;
}
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, y;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		pq.push({ x,y });
	}

	while (!pq.empty())
	{
		cout << pq.top().first << " " << pq.top().second << "\n";
		pq.pop();
	}

	return 0;
}
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct compare
{
	bool operator()(pair<int,int> a, pair<int, int> b)
	{
		if (a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, y;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

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
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;
	int n, num;

	cin >> n;
	while (n--)
	{
		cin >> num;
		pq.push(num);
	}

	while (!pq.empty())
	{
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}
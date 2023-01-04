#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	priority_queue<int> pq;

	cin >> num;

	while (num != 0)
	{
		pq.push(num % 10);
		num /= 10;
	}

	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}

	return 0;
}
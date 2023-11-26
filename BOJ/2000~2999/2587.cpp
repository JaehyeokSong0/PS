#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> pq;

	int num, mean = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		pq.push(num);
		mean += num;
	}

	pq.pop();
	pq.pop();

	cout << mean / 5 << "\n" << pq.top() << "\n";

	return 0;
}
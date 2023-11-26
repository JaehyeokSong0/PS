#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> pq;

	int n, k, num;
	cin >> n >> k;

	while (n--)
	{
		cin >> num;
		pq.push(num);
	}

	while(--k)
		pq.pop();
	
	cout << pq.top() << "\n";

	return 0;
}
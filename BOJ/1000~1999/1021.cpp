#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int answer = 0;

void moveLeft(deque<int>& dq, int count = 1)
{
	for (int i = 1; i <= count; i++)
	{
		dq.push_back(dq.front());
		dq.pop_front();
		answer++;
	}
}

void moveRight(deque<int>& dq, int count = 1)
{
	for (int i = 1; i <= count; i++)
	{
		dq.push_front(dq.back());
		dq.pop_back();
		answer++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	deque<int> dq(N);
	for (int i = 1; i <= N;i++)
		dq[i - 1] = i;

	int target;
	for (int i = 0; i < M; i++)
	{
		cin >> target;

		while (true)
		{
			if (dq.front() == target)
			{
				dq.pop_front();
				break;
			}
			else
			{
				int idx = find(dq.begin(), dq.end(), target) - dq.begin();
				int pos = idx - dq.size() / 2;
				if (pos <= 0) // 왼쪽에 있으니 moveLeft
				{
					moveLeft(dq, idx);
				}
				else // 오른쪽에 있으니 moveRight
				{
					moveRight(dq, dq.size() - idx);
				}
			}
		}
	}

	cout << answer << "\n";

	return 0;
}
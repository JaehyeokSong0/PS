#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, Q, C;

deque<int> frontCache;
deque<int> backCache;
int currentPage = -1;

vector<int> capacity;
int frontCapacity = 0;
int backCapacity = 0;

void backward()
{
	if (backCache.size() == 0)
		return;

	frontCache.push_back(currentPage);
	frontCapacity += capacity[currentPage];

	currentPage = backCache.back();
	backCache.pop_back();
	backCapacity -= capacity[currentPage];
}

void frontward()
{
	if (frontCache.size() == 0)
		return;

	backCache.push_back(currentPage);
	backCapacity += capacity[currentPage];

	currentPage = frontCache.back();
	frontCache.pop_back();
	frontCapacity -= capacity[currentPage];
}

void access(int webpage)
{
	frontCache.clear();
	frontCapacity = 0;

	if (currentPage != -1)
	{
		backCache.push_back(currentPage);
		backCapacity += capacity[currentPage];
	}

	currentPage = webpage;

	while (capacity[currentPage] + backCapacity + frontCapacity > C)
	{
		backCapacity -= capacity[backCache.front()];
		backCache.pop_front();
	}
}

void compress()
{
	deque<int> buffer;
	int check = -1;

	for (auto it = backCache.begin(); it != backCache.end(); it++)
	{
		if (check != *it)
		{
			check = *it;
			buffer.push_back(*it);
		}
		else
		{
			backCapacity -= capacity[*it];
		}
	}

	backCache = buffer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q >> C;

	int CAP;
	capacity.push_back(0); // capability[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> CAP;
		capacity.push_back(CAP);
	}

	char task;
	for (int i = 0; i < Q; i++)
	{
		cin >> task;
		switch (task)
		{
		case 'B':
			backward();
			break;
		case 'F':
			frontward();
			break;
		case 'A':
			int arg;
			cin >> arg;
			access(arg);
			break;
		case 'C':
			compress();
			break;
		}
	}

	cout << currentPage << "\n";

	if (backCache.size() > 0)
	{
		for (auto page = backCache.rbegin(); page < backCache.rend(); page++)
			cout << *page << " ";
	}
	else
		cout << -1;
	cout << "\n";

	if (frontCache.size() > 0)
	{
		for (auto page = frontCache.rbegin(); page < frontCache.rend(); page++)
			cout << *page << " ";
	}
	else
		cout << -1;
	cout << "\n";

	return 0;
}
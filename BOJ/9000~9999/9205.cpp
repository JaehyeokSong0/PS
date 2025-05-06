#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct loc
{
	short x;
	short y;
	bool visited;

	loc()
	{
		x = 0;
		y = 0;
		visited = false;
	}

	loc(short x, short y)
	{
		this->x = x;
		this->y = y;
		visited = false;
	}
};

loc home;
vector<loc> stores;
loc festival;


void inputProcess(short n)
{
	stores.clear();

	int f, s;

	cin >> f >> s;
	home = loc(f, s);

	while (n--)
	{
		cin >> f >> s;
		stores.push_back(loc(f, s));
	}

	cin >> f >> s;
	festival = loc(f, s);
}

int getDist(loc& src, loc& dst)
{
	return abs(src.x - dst.x) + abs(src.y - dst.y);
}

bool bfs()
{
	queue<loc> q;
	q.push(home);

	while (!q.empty())
	{
		loc curr = q.front();
		q.pop();

		if (getDist(curr, festival) <= 1000)
		{
			return true;
		}

		for (loc& store : stores)
		{
			if (store.visited == true)
				continue;

			if (getDist(curr, store) <= 1000)
			{
				store.visited = true;
				q.push(store);
			}
		}
	}

	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;

		inputProcess(n);

		bool result = bfs();

		if (result)
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}
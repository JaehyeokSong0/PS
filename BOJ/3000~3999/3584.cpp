#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX_SIZE 10001
int parent[MAX_SIZE] = { 0, };

int getDepth(int node, int root)
{
	int depth = 0;

	while (node != root)
	{
		node = parent[node];
		depth++;
	}
	
	return depth;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		memset(parent, 0, sizeof(parent));

		cin >> N;

		int root;
		for (int n = 0; n < N - 1; n++)
		{
			int A, B;
			cin >> A >> B;

			parent[B] = A;
		}

		for (int n = 1; n <= N; n++)
		{
			if (parent[n] == 0)
			{
				root = n;
				break;
			}
		}

		int x, y;
		cin >> x >> y;

		int dx = getDepth(x, root);
		int dy = getDepth(y, root);

		if (dx > dy)
		{
			for (int i = 0; i < dx - dy; i++)
			{
				x = parent[x];
			}
			dx = dy;
		}
		else if (dy > dx)
		{
			for (int i = 0; i < dy - dx; i++)
			{
				y = parent[y];
			}
			dy = dx;
		}

		while (x != y)
		{
			x = parent[x];
			y = parent[y];
		}

		cout << x << "\n";
	}

	return 0;
}
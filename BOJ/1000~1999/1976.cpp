#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& root, int index)
{
	if (root[index] == index)
	{
		return index;
	}
	else
	{
		return find(root, root[index]);
	}
}

void makeUnion(vector<int>& root, int x, int y)
{
	x = find(root, x);
	y = find(root, y);

	root[y] = x;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> root(N + 1, 0);
	for (int i = 0; i < N + 1; i++)
		root[i] = i;

	int input;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> input;

			if (input == 1 && i != j)
			{
				makeUnion(root, i, j);
			}
		}
	}

	cin >> input;
	int start = find(root, input);

	while (cin >> input)
	{
		if (start != find(root, input))
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}
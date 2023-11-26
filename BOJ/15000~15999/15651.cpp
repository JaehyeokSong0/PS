#include <iostream>
using namespace std;

#define MAXSIZE 9

int n, m;
int arr[MAXSIZE] = { 0, };

void dfs(int x) // x: dfs È½¼ö(±íÀÌ)
{
	if (x == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			arr[x] = i;
			dfs(x + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	dfs(0);

	return 0;
}
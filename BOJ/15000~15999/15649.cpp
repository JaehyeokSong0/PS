#include <iostream>
using namespace std;

#define MAXSIZE 9

int n, m;
int arr[MAXSIZE] = { 0, };
bool check[MAXSIZE] = { false, };

void dfs(int x)
{
	if (x == m) // arr 개수가 m 만족 시 출력
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
			if (!check[i])
			{
				check[i] = true;
				arr[x] = i;
				dfs(x + 1);
				check[i] = false; // 백트래킹 위해 check 초기화
			}
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
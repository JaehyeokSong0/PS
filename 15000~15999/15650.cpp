#include <iostream>
using namespace std;

#define MAXSIZE 9

int n, m;
int arr[MAXSIZE] = { 0, };
bool check[MAXSIZE] = { false, };

void dfs(int x, int y) // x: dfs Ƚ��(����) / y: ���� dfs ���� �� ����� �� + 1
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
		for (int i = y; i <= n; i++)
		{
			if (!check[i])
			{
				check[i] = true;
				arr[x] = i;
				dfs(x + 1, i + 1);
				check[i] = false; // ��Ʈ��ŷ ���� check �ʱ�ȭ
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	dfs(0, 1);

	return 0;
}
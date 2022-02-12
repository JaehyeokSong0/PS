#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 12

int n;
int a[MAXSIZE] = { 0, };
int tmpA[MAXSIZE] = { 0, };
int op[5] = { 0, };
int opArr[MAXSIZE] = { 0, };
int tmpOpArr[MAXSIZE] = { 0, };
int maxRet = -1000000000;
int minRet = 1000000000;

int calc(int x, int y, int opt)
{
	if (opt == 1)
		return x + y;
	else if (opt == 2)
		return x - y;
	else if (opt == 3)
		return x * y;
	else if (opt == 4)
		return x / y;
}

void dfs(int x) // a[i] �����ؼ� ���ο� �迭 => 1�� �ݺ� : x,/ ����ؼ� �迭 ����, 2�� �ݺ� +,- ���
{
	if (x == n - 1)
	{
		int ret = 0;
		for (int i = 0; i < n; i++) // �迭 ����
		{
			tmpA[i] = a[i];
			tmpOpArr[i] = opArr[i];
		}
		for (int i = 0; i < n - 1; i++) // *,/ ���
		{
			if (tmpOpArr[i] >= 3)
			{
				ret = tmpA[i + 1] = calc(tmpA[i], tmpA[i + 1], tmpOpArr[i]);
				tmpOpArr[i] = -1; // ����� �����ڿ� -1 ǥ��
			}
		}
		for (int i = 0; i < n - 1; i++) // +,- ���
		{
			if (tmpOpArr[i] > 0) // �̻�� ������ operation�� ����
			{
				for (int j = i + 1; j < n; j++)
				{
					if (tmpOpArr[j] != -1)
					{
						ret = tmpA[j] = calc(tmpA[i], tmpA[j], tmpOpArr[i]);
						tmpOpArr[i] = -1;
						break;
					}
				}
			}
		}
		minRet = min(minRet, ret);
		maxRet = max(maxRet, ret);
	}
	else
	{
		for (int i = 1; i <= 4; i++)
		{
			if (op[i] > 0)
			{
				op[i]--;
				opArr[x] = i;
				dfs(x + 1);
				op[i]++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i <= 4; i++)
		cin >> op[i];

	dfs(0);

	cout << maxRet << endl << minRet << endl;

	return 0;
}
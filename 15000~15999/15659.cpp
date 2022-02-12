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

void dfs(int x) // a[i] 복사해서 새로운 배열 => 1번 반복 : x,/ 계산해서 배열 저장, 2번 반복 +,- 계산
{
	if (x == n - 1)
	{
		int ret = 0;
		for (int i = 0; i < n; i++) // 배열 복사
		{
			tmpA[i] = a[i];
			tmpOpArr[i] = opArr[i];
		}
		for (int i = 0; i < n - 1; i++) // *,/ 계산
		{
			if (tmpOpArr[i] >= 3)
			{
				ret = tmpA[i + 1] = calc(tmpA[i], tmpA[i + 1], tmpOpArr[i]);
				tmpOpArr[i] = -1; // 사용한 연산자에 -1 표시
			}
		}
		for (int i = 0; i < n - 1; i++) // +,- 계산
		{
			if (tmpOpArr[i] > 0) // 미사용 상태의 operation에 대해
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
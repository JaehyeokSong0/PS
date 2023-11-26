#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 501

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int prev[MAXSIZE] = { 0, };
	int curr[MAXSIZE] = { 0, };
	int num, ret = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cin >> num;
			if (j == 0) // 가장 왼쪽 숫자
				curr[j] = prev[j] + num;
			else if (j == i) // 가장 오른쪽 숫자
				curr[j] = prev[j] + num;
			else
				curr[j] = max(prev[j - 1], prev[j]) + num;
		}
		for (int j = 0; j < i; j++)
			prev[j] = curr[j];
	}
	for (int i = 0; i < n; i++)
		ret = max(ret, curr[i]);

	cout << ret;

	return 0;
}
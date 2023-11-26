#include <iostream>
using namespace std;

#define MAXSIZE 1000000+1
int memo[MAXSIZE]; //calc(n)�� �� memoization
int prevNum[MAXSIZE]; //���� node�� ����Ű�� array

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	memo[2] = memo[3] = 1;
	prevNum[2] = prevNum[3] = 1;

	for (int i = 4;i <= n;i++)
	{
		memo[i] = memo[i - 1] + 1; //memo[i]�� �ʱ갪 (�ݺ��� �����ϸ鼭 �� ���� �� �߰� �� ��ü)
		prevNum[i] = i - 1;
		if (i % 2 == 0)
		{
			if (memo[i] > memo[i / 2] + 1)
			{
				memo[i] = memo[i / 2] + 1;
				prevNum[i] = i / 2;
			}
		}
		if (i % 3 == 0)
		{
			if (memo[i] > memo[i / 3] + 1)
			{
				memo[i] = memo[i / 3] + 1;
				prevNum[i] = i / 3;
			}
		}
	}

	cout << memo[n] << "\n"; //���� Ƚ�� �ּڰ� ���
	//1�� ����� ������ �� ���
	cout << n << " "; 
	while (n != 1)
	{
		n = prevNum[n];
		cout << n << " ";
	}

	return 0;
}
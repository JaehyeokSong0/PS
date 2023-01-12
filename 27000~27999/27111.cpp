#include <iostream>
using namespace std;

#define MAXSIZE 200000+1
bool record[MAXSIZE] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, ret = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		if (b == 1) // a�� ���� ��
		{
			if (!record[a]) // ���� ����
				record[a] = true;
			else // �ִ� ����
				ret++;
		}
		else // a�� ������ ��
		{
			if (!record[a]) // ���� ����
				ret++;
			else
				record[a] = false;
		}
	}

	for (int i = 1; i < MAXSIZE; i++)
	{
		if (record[i]) // �� ����� ������ �ʾ��� ��
			ret++;
	}

	cout << ret << "\n";

	return 0;
}
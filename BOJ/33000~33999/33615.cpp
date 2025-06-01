#include <iostream>
#include <string>
using namespace std;

void solve(string N)
{
	int index = 0, divisor = 0;
	int sum = 0;

	for (auto it = N.begin(); it < N.end(); it++)
		sum += *it - '0';

	switch (sum % 3)
	{
	case 2:
	{
		auto it = N.find('5');
		if (it != string::npos)
		{
			index = it + 1;
			divisor = 3;
		}
		else // 1�θ� ������ ��
		{
			// ���̰� 2��� �ݵ�� 11�� ���. ��, �̹� �ռ���
			// �������� 1�̸� ���� �ϳ��� �����ϸ� ��
			if (N.length() % 2 != 0)
				index = 1;

			divisor = 11;
		}
	}
	break;
	case 1:
	{
		auto it = N.find('1');
		if (it != string::npos)
		{
			index = it + 1;
			divisor = 3;
		}
		else // 5�θ� ������ ��
			divisor = 5;
	}
	break;
	case 0: // �̹� �ռ����̹Ƿ� �������� �ʾƵ� ��
	{
		index = 0;
		divisor = 3;
	}
	break;
	}

	cout << index << " " << divisor << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		string N;
		cin >> N;

		solve(N);
	}

	return 0;
}
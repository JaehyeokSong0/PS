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
		else // 1로만 구성된 수
		{
			// 길이가 2배면 반드시 11의 배수. 즉, 이미 합성수
			// 나머지가 1이면 숫자 하나만 제거하면 됨
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
		else // 5로만 구성된 수
			divisor = 5;
	}
	break;
	case 0: // 이미 합성수이므로 제거하지 않아도 됨
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
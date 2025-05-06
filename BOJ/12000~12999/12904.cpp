#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S, T;
	cin >> S >> T;

	// T -> S�� �ٿ����� S�� ������ �� �ִ� ���� �Ǵ�
	int times = T.length() - S.length();
	for (int i = 0; i < times; i++)
	{
		if (T.back() == 'A') // A
		{
			T.pop_back();
		}
		else // B
		{
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}

	cout << (S == T) << "\n";

	return 0;
}
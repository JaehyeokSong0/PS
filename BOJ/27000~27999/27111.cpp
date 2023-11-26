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
		if (b == 1) // a가 들어갔을 때
		{
			if (!record[a]) // 없던 상태
				record[a] = true;
			else // 있던 상태
				ret++;
		}
		else // a가 나왔을 때
		{
			if (!record[a]) // 없던 상태
				ret++;
			else
				record[a] = false;
		}
	}

	for (int i = 1; i < MAXSIZE; i++)
	{
		if (record[i]) // 들어간 사람이 나오지 않았을 때
			ret++;
	}

	cout << ret << "\n";

	return 0;
}
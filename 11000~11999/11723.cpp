#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m; //m:수행할 연산의 수
	cin >> m;
	int S = 0; //S:집합 (초깃값 공집합)
	for (int i = 0; i < m; i++)
	{
		string op;
		int x;
		cin >> op;
		if ((op != "all") && (op != "empty"))
			cin >> x;
		if (op == "add")
			S |= 1 << (x - 1);
		else if (op == "remove")
			S &= ~(1 << (x - 1));
		else if (op == "check")
		{
			if (S & (1 << (x - 1)))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (op == "toggle")
			S ^= (1 << (x - 1));
		else if (op == "all")
			S = (1 << 20) - 1;
		else if (op == "empty")
			S = 0;
	}
	return 0;
}
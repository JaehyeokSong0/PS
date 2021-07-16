#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	while (cin >> a >> b)
	{
		if (a == 0)
			break;
		cout << a + b << endl;
	}

	return 0;
}
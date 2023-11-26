#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, chicken[3], ret = 0;
	cin >> n;
	for (int i = 0; i < 3; i++)
		cin >> chicken[i]; // a,b,c ¥Î√º

	for (int i = 0; i < 3; i++)
	{
		if (chicken[i] < n)
			ret += chicken[i];
		else
			ret += n;
	}

	cout << ret << "\n";

	return 0;
}
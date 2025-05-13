#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> lis;
	
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		auto it = lower_bound(lis.begin(), lis.end(), a);

		if (it == lis.end())
			lis.push_back(a);
		else
			*it = a;
	}

	cout << lis.size() << "\n";

	return 0;
}
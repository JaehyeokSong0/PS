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
	vector<int> arr;

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;

		auto it = lower_bound(arr.begin(), arr.end(), input);
		if (it == arr.end())
			arr.push_back(input);
		else
			*it = input;
	}

	cout << arr.size() << "\n";

	return 0;
}
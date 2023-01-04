#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, age;
	string name;
	vector<pair<int, string>> v;

	cin >> n;
	while (n--)
	{
		cin >> age >> name;
		v.push_back({ age, name });
	}

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}
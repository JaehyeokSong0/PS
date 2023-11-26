#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	vector<int> v_original;
	cin >> n;

	for(int i = 0;i<n;i++)
	{
		cin >> num;
		v_original.push_back(num);
	}

	vector<int> v_index(v_original);
	sort(v_index.begin(), v_index.end());
	v_index.erase(unique(v_index.begin(), v_index.end()), v_index.end());

	for (int i : v_original)
		cout << lower_bound(v_index.begin(), v_index.end(), i) - v_index.begin() << " "; // find() : O(N), lower_bound() : O(log N)

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int arrMode[8000] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num, sumNum = 0, minNum = 4001, maxNum = -4001, maxMode = -1;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		sumNum += num;
		minNum = min(minNum, num);
		maxNum = max(maxNum, num);
		v.push_back(num);

		maxMode = max(maxMode, ++arrMode[num + 4000]);
	}

	sort(v.begin(), v.end());

	vector<int> vMode;
	for (int i = -4000; i < 4001; i++)
	{
		int mode = arrMode[i + 4000];
		if (maxMode == mode)
			vMode.push_back(i);
		else if (maxMode < mode)
		{
			maxMode = mode;
			vMode.clear();
			vMode.push_back(i);
		};
	}

	cout << (int)round((double)sumNum / (double)n) << "\n";
	cout << v[n / 2] << "\n";
	if (vMode.size() == 1)
		cout << vMode[0] << "\n";
	else
		cout << vMode[1] << "\n";
	cout << maxNum - minNum << "\n";

	return 0;
}
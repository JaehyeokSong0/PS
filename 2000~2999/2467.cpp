#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> solution;
int n; //수의 개수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		solution.push_back(num);
	}

	int left = 0;
	int right = n - 1;

	int result = abs(solution[left] + solution[right]);
	int resultLeft = left;
	int resultRight = right;

	int sum;
	while (left < right)
	{
		sum = solution[left] + solution[right];
		if (abs(sum) < result)
		{
			result = abs(sum);
			resultLeft = left;
			resultRight = right;
		}
		else if (sum > 0)
			right--;
		else
			left++;
	}

	cout << solution[resultLeft] << " " << solution[resultRight];

	return 0;
}
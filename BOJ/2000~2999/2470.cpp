#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, value;
	cin >> N;

	vector<int> solutions;

	for (int i = 0; i < N; i++)
	{
		cin >> value;
		solutions.push_back(value);
	}

	sort(solutions.begin(), solutions.end());

	int left = 0, right = N - 1;
	int sum = INT_MAX;
	int answer_left = solutions[left], answer_right = solutions[right];

	// all acid
	if (solutions[left] >= 0)
	{
		right = left + 1;
		answer_right = solutions[right];
	}
	// all alkarine
	else if (solutions[right] <= 0)
	{
		left = right - 1;
		answer_left = solutions[left];
	}
	else
	{
		while (left < right)
		{
			if (solutions[left] + solutions[right] < 0)
			{
				if (abs(sum) > abs(solutions[left] + solutions[right]))
				{
					answer_left = solutions[left];
					answer_right = solutions[right];

					sum = solutions[left] + solutions[right];
				}

				left++;
			}
			else
			{
				if (abs(sum) > abs(solutions[left] + solutions[right]))
				{
					answer_left = solutions[left];
					answer_right = solutions[right];

					sum = solutions[left] + solutions[right];
				}

				right--;
			}
		}
	}

	cout << answer_left << " " << answer_right << "\n";

	return 0;
}
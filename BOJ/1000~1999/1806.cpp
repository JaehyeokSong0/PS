#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N_SIZE 100001
int arr[MAX_N_SIZE] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;
	cin >> N >> S;

	int answer = N + 1;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int sum = arr[0];

	while (start <= end)
	{
		if (sum >= S)
		{
			answer = min(answer, end - start + 1);
			
			sum -= arr[start];
			start++;
		}
		else
		{
			if (end < N - 1)
			{
				end++;
				sum += arr[end];	
			}
			else if (end == N - 1)
			{
				sum -= arr[start];
				start++;
			}
		}
	}

	if (answer == N + 1)
		answer = 0;

	cout << answer << "\n";

	return 0;
}
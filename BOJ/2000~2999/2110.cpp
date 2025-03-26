#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// �־��� distance�� �ּҰŸ��� C���� �����⸦ ��ġ�� �� ������ return true
/// </summary>
bool solve(int distance, int C, vector<int>& houses)
{
	int installed = 1;
	int prev = houses[0]; // ������ �����⸦ ��ġ�� ���� ��ǥ

	for (int i = 1; i < houses.size(); i++)
	{
		if (prev + distance <= houses[i])
		{
			installed++;
			prev = houses[i];
		}
	}

	return (installed >= C);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C;
	cin >> N >> C;

	vector<int> houses(N);
	for (int n = 0; n < N; n++)
	{
		cin >> houses[n];
	}

	sort(houses.begin(), houses.end());

	int start = 1;
	int end = houses[N - 1] - houses[0];
	int answer = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		// mid �Ÿ��� C����ŭ ��ġ�� �����ϸ� �Ÿ� �ø���
		if (solve(mid, C, houses) == true)
		{
			answer = mid;
			start = mid + 1;
		}
		// mid �Ÿ��� C����ŭ ��ġ�� �Ұ����ϸ� �Ÿ� ���̱�		
		else
		{
			end = mid - 1;
		}
	}

	cout << answer << "\n";

	return 0;
}
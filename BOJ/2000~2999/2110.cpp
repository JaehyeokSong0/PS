#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// 주어진 distance를 최소거리로 C개의 공유기를 설치할 수 있으면 return true
/// </summary>
bool solve(int distance, int C, vector<int>& houses)
{
	int installed = 1;
	int prev = houses[0]; // 이전에 공유기를 설치한 집의 좌표

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

		// mid 거리로 C개만큼 설치가 가능하면 거리 늘리기
		if (solve(mid, C, houses) == true)
		{
			answer = mid;
			start = mid + 1;
		}
		// mid 거리로 C개만큼 설치가 불가능하면 거리 줄이기		
		else
		{
			end = mid - 1;
		}
	}

	cout << answer << "\n";

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, L, H;
vector<pair<int, int>> pillar;
int warehouse[1001];
int startLoc = 1001, endLoc = -1;
int leftHeight = 0, rightHeight = 0;

int findTallestPillar()
// 중앙에 위치한 가장 큰 기둥 찾기
{
	int tallest = pillar[0].first;
	vector<int> tallestPillars;
	tallestPillars.push_back(pillar[0].second);
	int tallestCount = 1;
	for (int n = 1; n < N;n++)
	{
		if (tallest == pillar[n].first)
		{
			tallestPillars.push_back(pillar[n].second);
			tallestCount++;
		}
		else
			break;
	}
	sort(tallestPillars.begin(), tallestPillars.end());
	return tallestPillars[tallestCount / 2];
}

int findLeft(int base)
// 왼쪽에서 가장 큰 기둥 중 가장 먼 기둥 찾기
{
	int index = base;
	bool flag = false;
	for(int i = 0; i < N; i++)
	{
		if (pillar[i].second < base)
		{
			if (!flag)
			{
				leftHeight = pillar[i].first;
				index = pillar[i].second;
				flag = true;
			}
			else if (leftHeight > pillar[i].first)
				break;
			else
			{
				if (pillar[i].second < index)
					index = pillar[i].second;
			}
		}
	}
	return index;
}

int findRight(int base)
// 오른쪽에서 가장 큰 기둥 중 가장 먼 기둥 찾기
{
	int index = base;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		if (pillar[i].second > base)
		{
			if (!flag)
			{
				rightHeight = pillar[i].first;
				index = pillar[i].second;
				flag = true;
			}
			else if (rightHeight > pillar[i].first)
				break;
			else
			{
				if (pillar[i].second < index)
					index = pillar[i].second;
			}
		}
	}
	return index;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int n = 0;n < N;n++)
	{
		cin >> L >> H;
		pillar.push_back({ H, L });

		if (L < startLoc)
			startLoc = L;
		if (L > endLoc)
			endLoc = L;
	}

	// pillar를 높이 내림차순으로 저장
	sort(pillar.rbegin(), pillar.rend());

	int tallestPillar = findTallestPillar();
	warehouse[tallestPillar] = pillar[0].first;

	int left = tallestPillar;
	int exLeft;
	while (left > startLoc)
	{
		exLeft = left;
		left = findLeft(left);
		for (int l = left; l < exLeft; l++)
			warehouse[l] = leftHeight;
	}

	int right = tallestPillar;
	int exRight;
	while (right < endLoc)
	{
		exRight = right;
		right = findRight(right);
		for (int r = right; r > exRight; r--)
			warehouse[r] = rightHeight;
	}

	int result = 0;
	for (int loc = startLoc; loc <= endLoc; loc++)
		result += warehouse[loc];

	cout << result << "\n";

	return 0;
}
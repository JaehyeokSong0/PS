#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

/// <summary>
/// 이어붙인 정육면체의 조합이 정육면체와 유사한 모양을 가져야 공유하는 겉면이 많아져 겉넓이도 최소
/// n^3 (1, 8, 27, ...)
/// </summary>
/// <param name="size">정육면체의 개수</param>
int getMinWidth(int size, vector<int>& cubes)
{
	auto lb = lower_bound(cubes.begin(), cubes.end(), size);
	int lowerRoot = lb - cubes.begin();
	int upperRoot = lowerRoot + 1;

	if (size == *lb)
	{
		return (upperRoot * upperRoot) * 6;
	}

	int remain = size; // 남은 블록 개수
	int sum = 0; // 겉넓이의 총합

	if (upperRoot * upperRoot * lowerRoot <= remain) // 층의 넓이를 넓히는게 가능
	{
		remain = size - (upperRoot * upperRoot * lowerRoot);
		sum = (upperRoot * upperRoot) * 2 + (lowerRoot * upperRoot) * 4;

		while (remain) // 한 층 더 쌓기 가능
		{
			// 최소 정사각형
			int sqSize = (int)sqrt(remain); // 한 변
			sum += sqSize * 4;
			remain -= sqSize * sqSize;

			int attached = 0; // 스코프 내부에서 부착된 블록
			while (remain) // 구석에서 정사각형 넓혀가며 달팽이처럼 확장
			{
				if (attached % sqSize == 0) // 최초 OR 한 변 다 채움
				{
					sum += 2;
				}

				remain--;
				attached++;
			}
		}
	}
	else // 불가능
	{
		int count = 0;
		sum = lowerRoot * lowerRoot * 6;
		remain -= lowerRoot * lowerRoot * lowerRoot;

		while (remain && count < 2) // 두 축의 면에 붙이기
		{
			if (remain >= lowerRoot * lowerRoot)
			{
				sum += lowerRoot * 4;
				remain -= lowerRoot * lowerRoot;
				count++;
			}
			else
				break;
		}

		if (count == 2) // 양 축에 다 붙었을 경우 : remain은 0 ~ lowerRoot 범위가 됨 
		{
			if (remain) // 어차피 양 변의 틈을 메꾸는 거라 1개만 있으나 여러개 있으나 겉넓이는 동일
			{
				sum += 2;
				remain = 0;
			}
		}
		else
		{
			// 최소 정사각형
			int sqSize = (int)sqrt(remain); // 한 변
			sum += sqSize * 4;
			remain -= sqSize * sqSize;

			int attached = 0; // 스코프 내부에서 부착된 블록
			while (remain) // 구석에서 정사각형 넓혀가며 달팽이처럼 확장
			{
				if (attached % sqSize == 0) // 최초 OR 한 변 다 채움
				{
					sum += 2;
				}

				remain--;
				attached++;
			}
		}

	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// N^3 배열
	vector<int> cubes;

	for (int i = 1; i <= 101; i++)
		cubes.push_back(i * i * i);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << getMinWidth(N, cubes) << "\n";
	}

	return 0;
}
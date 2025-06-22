#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, H;
	cin >> N >> H;

	// {height, count}
	map<int, int> statlagmite; // 석순
	map<int, int> stalactite; // 종유석

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (i % 2 == 0)
		{
			if (statlagmite.count(input) == 0)
				statlagmite[input] = 1;
			else
				statlagmite[input]++;
		}
		else
		{
			if (stalactite.count(input) == 0)
				stalactite[input] = 1;
			else
				stalactite[input]++;
		}
	}

	vector<int> obstacles(H + 1, 0); // obstacles[i] : (i-1) ~ i 에 있는 장애물

	// 석순 계산
	int prevHeight = 0;
	int prevCount = 0;
	for (auto it = statlagmite.rbegin(); it != statlagmite.rend(); it++)
	{
		int height = it->first;
		int count = it->second;

		if (prevHeight != 0)
		{
			for (int i = height; i < prevHeight; i++)
			{
				obstacles[i] += prevCount;
			}
		}

		obstacles[height] += count;

		prevHeight = height;
		prevCount += count;
	}
	// 마지막 석순부터 바닥까지 보정
	for (int i = prevHeight - 1; i >= 1; i--)
		obstacles[i] += prevCount;

	// 종유석 계산
	prevHeight = 0;
	prevCount = 0;
	for (auto it = stalactite.rbegin(); it != stalactite.rend(); it++)
	{
		int height = H + 1 - it->first;
		int count = it->second;

		if (prevHeight != 0)
		{
			for (int i = height; i > prevHeight; i--)
			{
				obstacles[i] += prevCount;
			}
		}

		obstacles[height] += count;

		prevHeight = height;
		prevCount += count;
	}

	// 마지막 종유석부터 천장까지 보정
	for (int i = prevHeight + 1; i <= H; i++)
		obstacles[i] += prevCount;

	sort(obstacles.begin(), obstacles.end());

	int obstacles_min = obstacles[1];
	int obstacles_count = 0;
	for (int i = 1; i <= H; i++)
	{
		if (obstacles_min == obstacles[i])
			obstacles_count++;
		else
			break;
	}

	cout << obstacles_min << " " << obstacles_count << "\n";

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int getDistance(int fromX, int fromY, int toX, int toY)
{
	return abs(fromX - toX) + abs(fromY - toY);
}

vector<vector<bool>> getCombination(int n, int r)
{
	vector<vector<bool>> ret;
	vector<bool> sub(n, false);

	for (int i = n - r; i < n;i++)
		sub[i] = true;
	
	do 
	{
		ret.push_back(sub);
	} 
	while (next_permutation(sub.begin(), sub.end()));

	return ret;
}

int getChickenDistance(vector<bool> combination)
{
	int ret = 0;

	for (auto& h : house)
	{
		int minDist = 1e9;

		for (int i = 0; i < chicken.size(); i++)
		{
			if (combination[i] == true)
			{
				minDist = min(minDist, getDistance(h.first, h.second, chicken[i].first, chicken[i].second));
			}
		}
	
		ret += minDist;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int answer = 1e9;

	int map;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map;

			if (map == 1)
			{
				house.push_back({ i,j });
			}
			else if (map == 2)
			{
				chicken.push_back({ i,j });
			}
		}
	}

	vector<vector<bool>> combinations = getCombination(chicken.size(), M);
	for (auto& c : combinations)
	{
		answer = min(answer, getChickenDistance(c));
	}

	cout << answer << "\n";

	return 0;
}
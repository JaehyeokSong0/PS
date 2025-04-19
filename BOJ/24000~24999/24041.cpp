#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct mealkit
{
	long long decayRate;
	long long expirationDate;
	bool isEssential;
};

int N, G, K;
unordered_map<int, mealkit> meals;

bool canEat(long long date)
{
	// Calculate & Sort
	vector<pair<long long, int>> bacterium;
	for (auto& it : meals)
	{
		auto meal = it.second;
		long long bacteriaCount = meal.decayRate * max(1LL, date - meal.expirationDate);
		bacterium.push_back({ bacteriaCount, it.first });
	}

	sort(bacterium.begin(), bacterium.end(), greater<>());

	int count = 0;
	long long bacteriaSum = 0;
	for (auto& bacteria : bacterium)
	{
		if (meals[bacteria.second].isEssential == true)
		{
			bacteriaSum += bacteria.first;
		}
		else // 중요하지 않은 재료
		{
			if (count < K) // 더 버릴 수 있으면
				count++;
			else // 더 버릴 수 없으면
				bacteriaSum += bacteria.first;
		}

		// 초과했으면 더 순회하지 않고 탈출
		if (bacteriaSum > G)
			return false;
	}

	return (bacteriaSum <= G);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> G >> K;

	for (int i = 1; i <= N; i++)
	{
		int S, L, O;
		cin >> S >> L >> O;

		meals.insert({ i, mealkit{ S, L, (O == 0) } });
	}

	long long left = 0, right = 2e9;
	while (left + 1 < right)
	{
		long long mid = (left + right) / 2;

		if (canEat(mid) == true)
		{
			left = mid; // 먹을 수 있는 날짜
		}
		else
		{
			right = mid - 1;
		}
	}

	if (canEat(right) == true)
		cout << right << "\n";
	else
		cout << left << "\n";

	return 0;
}
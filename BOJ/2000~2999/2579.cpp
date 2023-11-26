#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 301

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int stair[MAXSIZE];
	int memo[MAXSIZE]; // 계단별 최대 점수
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
		cin >> stair[i];
	memo[0] = stair[0];
	memo[1] = stair[0] + stair[1];
	memo[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < t; i++)
		memo[i] = max(stair[i] + stair[i - 1] + memo[i - 3], stair[i] + memo[i - 2]); // 한 칸 점프 : 그 전 시행에는 반드시 두 칸 점프했어야 함 / 두 칸 점프 : 그 전 시행과 무관

	cout << memo[t - 1] << "\n";

	return 0;
}
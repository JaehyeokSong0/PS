#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 1000000+1
int memo[MAXSIZE] = { 0, }; //연산 횟수의 최솟값 memoization

int main()
{
	int n;
	cin >> n;
	memo[2] = memo[3] = 1;

	for (int i = 4;i <= n;i++)
	{
		memo[i] = memo[i - 1] + 1; //memo[i]의 초깃값 (반복문 수행하면서 더 작은 값 발견 시 교체)
		if (i % 2 == 0)
			memo[i] = min(memo[i], memo[i / 2] + 1);
		if (i % 3 == 0)
			memo[i] = min(memo[i], memo[i / 3] + 1);
	}

	cout << memo[n];

	return 0;
}
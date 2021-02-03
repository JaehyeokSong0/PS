#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 1000000+1
int memo[MAXSIZE]; //calc(n)의 값 memoization

int calc(int n)
{
	if (n == 1)
		return 0;
	else if (memo[n] > 0) //이미 구한 calc(n)값이면 바로 값 반환
		return memo[n];
	memo[n] = calc(n - 1) + 1; //calc(n)의 초깃값 (아래 과정을 수행하면서 더 작은 값 발견 시 교체)
	if (n % 2 == 0)
		memo[n] = min(memo[n], calc(n / 2) + 1); //현재까지 저장된 calc(n)값보다 calc(n/2)+1이 더 작으면 memo[n]값 교체
	if (n % 3 == 0)
		memo[n] = min(memo[n], calc(n / 3) + 1);
	return memo[n];
}

int main()
{
	int n;
	cin >> n;

	cout << calc(n);
	return 0;
}
#include <iostream>
using namespace std;

#define MAXSIZE 1000000+1
int memo[MAXSIZE]; //calc(n)의 값 memoization
int prevNum[MAXSIZE]; //이전 node를 가리키는 array

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	memo[2] = memo[3] = 1;
	prevNum[2] = prevNum[3] = 1;

	for (int i = 4;i <= n;i++)
	{
		memo[i] = memo[i - 1] + 1; //memo[i]의 초깃값 (반복문 수행하면서 더 작은 값 발견 시 교체)
		prevNum[i] = i - 1;
		if (i % 2 == 0)
		{
			if (memo[i] > memo[i / 2] + 1)
			{
				memo[i] = memo[i / 2] + 1;
				prevNum[i] = i / 2;
			}
		}
		if (i % 3 == 0)
		{
			if (memo[i] > memo[i / 3] + 1)
			{
				memo[i] = memo[i / 3] + 1;
				prevNum[i] = i / 3;
			}
		}
	}

	cout << memo[n] << "\n"; //연산 횟수 최솟값 출력
	//1로 만드는 과정의 수 출력
	cout << n << " "; 
	while (n != 1)
	{
		n = prevNum[n];
		cout << n << " ";
	}

	return 0;
}
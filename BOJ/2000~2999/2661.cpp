#include <iostream>
using namespace std;

#define MAXSIZE 81

int n;
int sequence[MAXSIZE];
bool found = false;

bool promising(int len) // depth : 검사할 수열의 길이
{
	for (int size = 1; size <= len / 2; size++) // size를 늘려가며 수열 내 중복성 검사
	{
		int cnt = 0;
		for (int idx = 0; idx < len -size; idx++)
		{
			if (sequence[idx] == sequence[idx + size])
				cnt++;
			else
				cnt = 0;
			if(cnt == size)
				return false;
		}
	}
	return true;
}

void solve(int depth)
{
	if (found)
		return;
	if (depth == n)
	{
		found = true;
		for (int i = 0; i < n; i++)
			cout << sequence[i];
		return;
	}
	else
	{
		for (int i = 1; i <= 3; i++)
		{
			sequence[depth] = i;
			if (promising(depth + 1))
				solve(depth + 1);
			sequence[depth] = 4;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		sequence[i] = 4;

	solve(0);

	return 0;
}
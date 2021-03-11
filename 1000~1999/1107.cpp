#include <iostream>
#include <memory.h>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

#define MAXSIZE 1000000+1 //500000보다 자릿수가 클 수 있으므로
bool button[10]; //망가지지 않았으면 true, 망가졌으면 false
bool isAvailable(int num)
{
	if (num == 0)
		return button[0];
	while (num != 0)
	{
		if (!button[num % 10])
			return false;
		num /= 10;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(button, true, sizeof(button));
	int n; //n:이동하려고 하는 채널
	int m; //m:고장난 버튼의 개수
	cin >> n >> m;

	while (m--)
	{
		int btn;
		cin >> btn;
		button[btn] = false;
	}

	int ret = MAXSIZE;
	int length = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (isAvailable(i))
		{
			int check = abs(i - n);
			if (check < ret)
			{
				ret = check;
				length = to_string(i).length();
			}
		}
	}

	cout << min(ret + length, abs(100 - n));

	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

void HaNoi(int from, int to, int num)
{
	int rest = 6 - (from + to);

	if (num == 1)
		cout << from << " " << to << "\n";
	else
	{
		HaNoi(from, rest, num - 1); // 최하단 원판 제외 rest로 이동
		cout << from << " " << to << "\n"; // 목표 위치로 최하단 원판 이동
		HaNoi(rest, to, num - 1); // rest로 이동한 (num - 1) 크기 탑 원래 목표 위치로 이동
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	cout << (int)pow(2, n) - 1 << "\n";
	HaNoi(1, 3, n);

	return 0;
}
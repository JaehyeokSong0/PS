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
		HaNoi(from, rest, num - 1); // ���ϴ� ���� ���� rest�� �̵�
		cout << from << " " << to << "\n"; // ��ǥ ��ġ�� ���ϴ� ���� �̵�
		HaNoi(rest, to, num - 1); // rest�� �̵��� (num - 1) ũ�� ž ���� ��ǥ ��ġ�� �̵�
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
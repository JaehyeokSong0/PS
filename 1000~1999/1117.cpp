#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long w, h, f, c, x1, y1, x2, y2;

	cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;

	long long painted = ((x2 - x1) * (y2 - y1)) * (c + 1);
	if (2 * f < w) // ���ʺ��� �������� Ŭ ��
	{
		if (x2 <= f) // x1, x2 ��� ���� ��ģ �κ� �ȿ� ���� ��
			painted *= 2;
		else if (f > x1) // x = 2f ���� �������� x1�� ����, x2�� �����ʿ� ���� ��
			painted += ((f - x1) * (y2 - y1)) * (c + 1);
	}
	else if (2 * f == w)
		painted *= 2;
	else // ������ �����ʺ��� Ŭ ��
	{
		if (f + x2 <= w) // x1, x2 ��� ���� ��ģ �κ� �ȿ� ���� ��
			painted *= 2;
		else if (f + x1 < w) // x = w ���� �������� x1�� ����, x2�� �����ʿ� ���� ��
			painted += ((w - f - x1) * (y2 - y1)) * (c + 1);
	}

	cout << (w * h) - painted << "\n";

	return 0;
}
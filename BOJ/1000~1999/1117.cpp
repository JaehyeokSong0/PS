#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long w, h, f, c, x1, y1, x2, y2;

	cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;

	long long painted = ((x2 - x1) * (y2 - y1)) * (c + 1);
	if (2 * f < w) // 왼쪽보다 오른쪽이 클 때
	{
		if (x2 <= f) // x1, x2 모두 접혀 겹친 부분 안에 있을 때
			painted *= 2;
		else if (f > x1) // x = 2f 지점 기준으로 x1은 왼쪽, x2는 오른쪽에 있을 때
			painted += ((f - x1) * (y2 - y1)) * (c + 1);
	}
	else if (2 * f == w)
		painted *= 2;
	else // 왼쪽이 오른쪽보다 클 때
	{
		if (f + x2 <= w) // x1, x2 모두 접혀 겹친 부분 안에 있을 때
			painted *= 2;
		else if (f + x1 < w) // x = w 지점 기준으로 x1은 왼쪽, x2는 오른쪽에 있을 때
			painted += ((w - f - x1) * (y2 - y1)) * (c + 1);
	}

	cout << (w * h) - painted << "\n";

	return 0;
}
/*
	삼각형 형태의 수 : k^2
	ex) 4 = 1+2+1, 9 = 1+2+3+2+1
	사다리꼴 형태의 수 : k * (k+1)
	ex) 6 = 1+2+2+1, 12 = 1+2+3+3+2+1
	공간이동 장치 작동 횟수는 위 형태의 수가 등장하는 경우마다 1씩 증가한다.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, x, y;
	cin >> T;
	
	while (T--)
	{
		cin >> x >> y;
		int distance = y - x;
		int flsq_distance = floor(sqrt(distance));
		int ret;
		
		if (distance > flsq_distance * (flsq_distance + 1))
			ret = 2 * flsq_distance + 1;
		else if (distance > flsq_distance * flsq_distance)
			ret = 2 * flsq_distance;
		else
			ret = 2 * flsq_distance - 1;
		cout << ret << endl;
	}

	return 0;
}
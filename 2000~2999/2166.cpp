#include <iostream>
#include <math.h>
using namespace std;

double xy[10001][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	double ret = 0.0f;
	cin >> n;	// �ٰ����� �̷�� ���� ����
	for (int i = 0; i < n; i++)
		cin >> xy[i][0] >> xy[i][1];

	for (int i = 0; i < n; i++)	// �Ź߲� ���� ���
		ret += (xy[i][0] * xy[(i + 1) % n][1] - (xy[(i + 1) % n][0] * xy[i][1])) / 2.0f;
	ret = fabs(ret);

	cout << fixed;
	cout.precision(1);
	cout << ret;
	return 0;
}
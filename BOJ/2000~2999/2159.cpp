#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


typedef pair<int, int> pos;
typedef long long ll;

const ll MAX_DIST = 2e11; // (�ִ� �Ÿ� : 2e5) * (�ִ� �ο� : 1e5) = 2e10. �˳��ϰ� 2e11�� ����
pos direction[5] = { {0,0}, {0,1}, {1,0}, {0,-1}, {-1,0} }; // �߾� �� �� �� ��

pos operator+(const pos& x, const pos& y)
{
	return pos(x.first + y.first, x.second + y.second);
}

int getDistance(const pos& x, const pos& y)
{
	return abs(x.first - y.first) + abs(x.second - y.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, restaurant_x, restaurant_y;
	pos restaurant;

	cin >> N >> restaurant_x >> restaurant_y;
	restaurant = { restaurant_x, restaurant_y };

	vector<pos> customers(N);

	int customer_x, customer_y;
	for (int i = 0; i < N; i++)
	{
		cin >> customer_x >> customer_y;

		customers[i] = { customer_x, customer_y };
	}

	vector<vector<ll>> dist(N, vector<ll>(5, MAX_DIST)); // {�� �ε���, ����}�� ���� ���� �ּҰŸ�

	// 0��° ���� ���� �ʱ�ȭ
	for (int dir = 0; dir < 5; dir++)
	{
		dist[0][dir] = getDistance(restaurant, customers[0] + direction[dir]);
	}
	
	int minDist = 2e9;
	// ���� ���鿡 ���ؼ�
	for (int customerIdx = 1; customerIdx < N; customerIdx++)
	{
		// ���� ���� ��ġ ���� ���� ����
		for (int currDir = 0; currDir < 5; currDir++)
		{
			// ���� ���� ��ġ ���� �� ����
			for (int nextDir = 0; nextDir < 5; nextDir++)
			{
				ll cost = getDistance(customers[customerIdx - 1] + direction[currDir], customers[customerIdx] + direction[nextDir]) // ���� ��ġ ~ ���� ��ġ�� �Ÿ� �ּڰ���
					+ dist[customerIdx - 1][currDir]; // ���� ��ġ �ּڰ��� ���� => ���� ��ġ������ �ּڰ�

				dist[customerIdx][nextDir] = min(dist[customerIdx][nextDir], cost);
			}
		}
	}

	ll answer = MAX_DIST;
	for (int i = 0; i < 5; i++)
		answer = min(answer, dist[N - 1][i]);

	cout << answer;

	return 0;
}
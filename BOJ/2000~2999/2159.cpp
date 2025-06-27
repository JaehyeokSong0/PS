#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


typedef pair<int, int> pos;
typedef long long ll;

const ll MAX_DIST = 2e11; // (최대 거리 : 2e5) * (최대 인원 : 1e5) = 2e10. 넉넉하게 2e11로 설정
pos direction[5] = { {0,0}, {0,1}, {1,0}, {0,-1}, {-1,0} }; // 중앙 상 우 하 좌

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

	vector<vector<ll>> dist(N, vector<ll>(5, MAX_DIST)); // {고객 인덱스, 방향}에 대한 누적 최소거리

	// 0번째 고객에 대해 초기화
	for (int dir = 0; dir < 5; dir++)
	{
		dist[0][dir] = getDistance(restaurant, customers[0] + direction[dir]);
	}
	
	int minDist = 2e9;
	// 다음 고객들에 대해서
	for (int customerIdx = 1; customerIdx < N; customerIdx++)
	{
		// 현재 고객의 위치 가능 값을 통해
		for (int currDir = 0; currDir < 5; currDir++)
		{
			// 다음 고객의 위치 가능 값 설정
			for (int nextDir = 0; nextDir < 5; nextDir++)
			{
				ll cost = getDistance(customers[customerIdx - 1] + direction[currDir], customers[customerIdx] + direction[nextDir]) // 현재 위치 ~ 다음 위치의 거리 최솟값을
					+ dist[customerIdx - 1][currDir]; // 현재 위치 최솟값에 누적 => 다음 위치까지의 최솟값

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
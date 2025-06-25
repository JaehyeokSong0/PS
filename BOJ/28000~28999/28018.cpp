#include <iostream>
#include <vector>
using namespace std;

#define MAX_TIME 1000000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S, E, Q;
	cin >> N;

	vector<int> diff(MAX_TIME + 2, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> S >> E;
		diff[S]++;
		diff[E + 1]--;
	}

	vector<int> seats(MAX_TIME + 1, 0);
	for (int i = 1; i <= MAX_TIME; i++)
		seats[i] += seats[i - 1] + diff[i];

	cin >> Q;
	int time;
	for (int i = 0; i < Q; i++)
	{
		cin >> time;
		cout << seats[time] << "\n";
	}

	return 0;
}
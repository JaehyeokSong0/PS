#include <iostream>
#include <vector>
using namespace std;

long long eat(int N, long long X, vector<long long>& layers)
{
	if (N == 0)
		return 1;

	// B L(N-1) P L(N-1) B
	if (X <= 1) // B
		return 0;
	else if (X <= 1 + layers[N - 1]) // B ~ before P
		return eat(N - 1, X - 1, layers);
	else if (X == 2 + layers[N - 1]) // B ~ P
		return (layers[N - 1] / 2) + 2;
	else
	{
		long long patty = (layers[N - 1] / 2) + 2;
		return patty + eat(N - 1, X - layers[N - 1] - 2, layers);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	long long X;
	cin >> N >> X;

	vector<long long> layers(51); // all layer
	// bun = layer / 2
	// patty = layer / 2 + 1

	layers[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		layers[i] = layers[i - 1] * 2 + 3;
		// layers[i] = (long long)(pow(2, n + 2)) - 3;
	}

	cout << eat(N, X, layers);

	return 0;
}
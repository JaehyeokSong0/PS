#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

typedef long long ll;

ll getElem(unordered_map<ll, ll>& arr, ll index, int P, int Q)
{
	if (arr.find(index) != arr.end())
		return arr[index];

	arr[index] = getElem(arr, floor(index / P), P, Q) + getElem(arr, floor(index / Q), P, Q);

	return arr[index];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N;
	int P, Q;
	cin >> N >> P >> Q;

	unordered_map<ll, ll> A;
	A[0] = 1;

	cout << getElem(A, N, P, Q) << "\n";

	return 0;
}
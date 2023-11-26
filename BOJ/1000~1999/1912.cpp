#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 100001
int n, arr[MAXSIZE] = { 0, }, memo[MAXSIZE] = { 0, }, ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	ret = memo[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		memo[i] = max(memo[i - 1] + arr[i], arr[i]);
		ret = max(ret, memo[i]);
	}
	cout << ret;

	return 0;
}
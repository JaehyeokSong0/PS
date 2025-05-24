#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++)
		arr[i] = i; 
	// Sum = (N - 1)개 : i가 1일 때 제외

	if (n == k)
	{
		cout << "Impossible\n";

		return 0;
	}

	// 1의 앞쪽 인덱스로 밀어버리면 Sum--와 동일
	for (int i = 2; i <= n - k; i++) // 조건 불만족 n - k개
		cout << i << " ";
	cout << "1 ";
	for (int i = n - k + 1; i <= n; i++) // 조건 만족 K개
		cout << i << " ";
	cout << "\n";

	return 0;
}
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
	// Sum = (N - 1)�� : i�� 1�� �� ����

	if (n == k)
	{
		cout << "Impossible\n";

		return 0;
	}

	// 1�� ���� �ε����� �о������ Sum--�� ����
	for (int i = 2; i <= n - k; i++) // ���� �Ҹ��� n - k��
		cout << i << " ";
	cout << "1 ";
	for (int i = n - k + 1; i <= n; i++) // ���� ���� K��
		cout << i << " ";
	cout << "\n";

	return 0;
}
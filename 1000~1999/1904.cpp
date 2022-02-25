#include <iostream>
using namespace std;

#define MAXSIZE 1000001

int arr[MAXSIZE] = { 1,2 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 2; i < n; i++)
		arr[i] = (arr[i - 2] + arr[i - 1])%15746;
	
	cout << arr[n-1];
	return 0;
}
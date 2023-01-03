#include <iostream>
using namespace std;

#define MAXSIZE 10000+1
int arr[MAXSIZE] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[num]++;
	}

	for (int i = 1; i < MAXSIZE; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			cout << i << "\n";
	}

	return 0;
}
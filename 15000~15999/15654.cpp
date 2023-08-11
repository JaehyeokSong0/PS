#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
bool check[9];
int indexArr[9];
int N, M;

void dfs(int index, int num)
{
	if (num == M)
	{
		for (int i = 0;i < M;i++)
			cout << arr[indexArr[i]] << " ";
		cout << "\n";
	}
	else
	{
		for (int i = 0;i < N;i++)
		{
			if (!check[i])
			{
				check[i] = true;
				indexArr[num] = i;
				dfs(i, num + 1);
				check[i] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int num;
	for (int n = 0;n < N;n++)
	{
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	
	dfs(0, 0);

	return 0;
}
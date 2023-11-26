#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define MAXSIZE 1000000+1
#define MINVALUE -1000000001
int arr[MAXSIZE];
vector<int> lis; //�׻� ���� lis��� ������ �� ������, ���� lis�� �� ũ��� �׻� ����.
int lisCnt[MAXSIZE]; //arr�� �� ������ lis�� ũ�⸦ �����ϱ� ���� �迭 (i��°���� lis.size�� ������)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> arr[i];
	lis.push_back(MINVALUE); //lis[0]�� ���� �� ���� ������ �ʱ�ȭ

	//LIS
	for (int i = 1;i <= n;i++)
	{
		if (lis.back() < arr[i])
		{
			lis.push_back(arr[i]);
			lisCnt[i] = lis.size() - 1;
		}
		else
		{
			auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
			*it = arr[i];
			int index = (it - lis.begin()); //arr[i]�� ��ü�Ǵ� ���� ���� lis���� ������ �����Ƿ� �ε����� ����.
			lisCnt[i] = index;
		}
	}
	int lisSize = lis.size() - 1;
	cout << lisSize << "\n"; //lis[0] ����

	stack<int> st;
	for (int i = n;i >= 1;i--)
	{
		if (lisCnt[i] == lisSize)
		{
			st.push(arr[i]);
			lisSize--;
		}
	}

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}
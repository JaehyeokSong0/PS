#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define MAXSIZE 1000000+1
#define MINVALUE -1000000001
int arr[MAXSIZE];
vector<int> lis; //항상 실제 lis라고 보장할 순 없지만, 실제 lis와 그 크기는 항상 같다.
int lisCnt[MAXSIZE]; //arr의 각 원소의 lis의 크기를 저장하기 위한 배열 (i번째까지 lis.size의 누적합)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> arr[i];
	lis.push_back(MINVALUE); //lis[0]을 나올 수 없는 값으로 초기화

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
			int index = (it - lis.begin()); //arr[i]는 대체되는 값과 같은 lis값을 가지고 있으므로 인덱스가 같다.
			lisCnt[i] = index;
		}
	}
	int lisSize = lis.size() - 1;
	cout << lisSize << "\n"; //lis[0] 제외

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
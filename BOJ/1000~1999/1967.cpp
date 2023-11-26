#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

#define MAXSIZE 10000+1
int n; //����� ����
vector<pair<int, int>> adjList[MAXSIZE]; //first: �������, second: ����ġ
bool check[MAXSIZE] = { false, };
int endPoint1 = 0; //������ �� ����
int ret = 0; //�����

void dfs(int node,int weightSum)
{
	if (weightSum > ret)
	{
		ret = weightSum;
		endPoint1 = node;
	}
	check[node] = true;
	for (int i = 0;i < adjList[node].size();i++)
	{
		int next = adjList[node][i].first;
		if(!check[next])
			dfs(next, weightSum + adjList[node][i].second);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0;i < n-1;i++)
	{
		int parent, child, weight;
		cin >> parent >> child >> weight;
		adjList[parent].push_back({ child,weight });
		adjList[child].push_back({ parent,weight });
	}

	//������ �� ���κ��� ���� �� ���� �ִ� ���� �ݵ�� ������ �� ��� �� �ϳ��̴�.
	dfs(1,0); //�� �� �� ���� ã�� ��
	//�ٽ� dfs�� �غ�
	memset(check, false, sizeof(check));
	ret = 0;

	dfs(endPoint1, 0);
	cout << ret;

	return 0;
}
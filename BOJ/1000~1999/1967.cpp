#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

#define MAXSIZE 10000+1
int n; //노드의 개수
vector<pair<int, int>> adjList[MAXSIZE]; //first: 인접노드, second: 가중치
bool check[MAXSIZE] = { false, };
int endPoint1 = 0; //지름의 한 끝점
int ret = 0; //결과값

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

	//임의의 한 노드로부터 가장 먼 곳에 있는 노드는 반드시 지름의 끝 노드 중 하나이다.
	dfs(1,0); //한 쪽 끝 점을 찾은 후
	//다시 dfs할 준비
	memset(check, false, sizeof(check));
	ret = 0;

	dfs(endPoint1, 0);
	cout << ret;

	return 0;
}
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAXSIZE 8 //노드의 개수
vector<int> adjList[MAXSIZE]; //연결리스트 (index 순서 : 0정보과학, 1전산, 2미래, 3신양, 4한경직기념, 5진리, 6형남, 7학생회) 
long long node[MAXSIZE] = { 0, }; //n분 후에 각 노드에 도달할 수 있는 경우의 수

void initAdjList();
void calc(long long node[]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initAdjList();
	node[1] = node[2] = 1; //1분 후의 경우를 초깃값

	int d; //산책 시간
	cin >> d;

	for (int i = 1;i < d;i++)
		calc(node);

	cout << node[0] % 1000000007;

	return 0;
}

void initAdjList()
{
	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[1].push_back(0);
	adjList[1].push_back(2);
	adjList[1].push_back(3);
	adjList[2].push_back(0);
	adjList[2].push_back(1);
	adjList[2].push_back(3);
	adjList[2].push_back(4);
	adjList[3].push_back(1);
	adjList[3].push_back(2);
	adjList[3].push_back(4);
	adjList[3].push_back(5);
	adjList[4].push_back(2);
	adjList[4].push_back(3);
	adjList[4].push_back(5);
	adjList[4].push_back(6);
	adjList[5].push_back(3);
	adjList[5].push_back(4);
	adjList[5].push_back(7);
	adjList[6].push_back(4);
	adjList[6].push_back(7);
	adjList[7].push_back(5);
	adjList[7].push_back(6);
}
//이동할 수 있는 노드에 대해 현재 node 값 더해줌
void calc(long long node[])
{
	long long tmp[MAXSIZE] = { 0, };
	for (int i = 0;i < MAXSIZE;i++) //모든 노드에 대해
	{	
		for (int j = 0;j < adjList[i].size();j++) //인접 노드에 더해줌
			tmp[adjList[i][j]] += node[i];
	}
	
	for (int i = 0;i < MAXSIZE;i++) //node에 복사
		*(node + i) = tmp[i] % 1000000007;
}
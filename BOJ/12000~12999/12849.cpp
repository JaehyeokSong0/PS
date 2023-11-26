#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAXSIZE 8 //����� ����
vector<int> adjList[MAXSIZE]; //���Ḯ��Ʈ (index ���� : 0��������, 1����, 2�̷�, 3�ž�, 4�Ѱ������, 5����, 6����, 7�л�ȸ) 
long long node[MAXSIZE] = { 0, }; //n�� �Ŀ� �� ��忡 ������ �� �ִ� ����� ��

void initAdjList();
void calc(long long node[]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initAdjList();
	node[1] = node[2] = 1; //1�� ���� ��츦 �ʱ갪

	int d; //��å �ð�
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
//�̵��� �� �ִ� ��忡 ���� ���� node �� ������
void calc(long long node[])
{
	long long tmp[MAXSIZE] = { 0, };
	for (int i = 0;i < MAXSIZE;i++) //��� ��忡 ����
	{	
		for (int j = 0;j < adjList[i].size();j++) //���� ��忡 ������
			tmp[adjList[i][j]] += node[i];
	}
	
	for (int i = 0;i < MAXSIZE;i++) //node�� ����
		*(node + i) = tmp[i] % 1000000007;
}
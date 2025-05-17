#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int left;
	int right;
	bool isPositive;
};

int N;
int negativeCount = 0, positiveCount = 0;

void dfs(vector<Node*>& tree, bool isPositive, int index)
{
	// 리프 노드면 이 노드가 최대여야 하는지, 최소여야 하는지 저장
	if (index <= N) // 리프 노드 판정
	{
		if (isPositive == true)
			positiveCount++;
		else
			negativeCount++;

		return;
	}

	// 연산자 노드에 대해
	if (tree[index]->isPositive == true)
	{
		dfs(tree, isPositive, tree[index]->left);
		dfs(tree, isPositive, tree[index]->right);
	}
	else
	{
		dfs(tree, isPositive, tree[index]->left);
		dfs(tree, !isPositive, tree[index]->right);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> values(N);
	vector<Node*> tree(2 * N + 1);
	for (int i = 0; i < N; i++)
		cin >> values[i];
	sort(values.begin(), values.end());

	char op;
	int left, right;
	for (int i = N + 1; i < 2 * N; i++)
	{
		cin >> op >> left >> right;

		tree[i] = new Node();
		tree[i]->isPositive = (op == '+');
		tree[i]->left = left;
		tree[i]->right = right;
	}

	dfs(tree, true, 2 * N - 1); // root부터 순회, positive 누적치는 노드가 아닌 간선부터 시작되는 것이므로 root의 isPositive는 항상 true

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (i < negativeCount)
			answer -= values[i];
		else
			answer += values[i];
	}

	cout << answer << "\n";

	return 0;
}
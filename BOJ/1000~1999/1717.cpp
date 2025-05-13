#include <iostream>
#include <vector>
using namespace std;

// root ��� ����
int find(int x, vector<int>& root)
{
	int answer = x;

	// �ֻ��� ��Ʈ �˻�
	while (answer != root[answer])
	{
		answer = root[answer];
	}

	// ����
	while (x != answer)
	{
		int prev = x;
		x = root[x]; // x�� �� �ܰ� ������ (����� root�� ���� ����Ǿ� ���� ����)
		root[prev] = answer; // ���� x�� root�� ������ �˻��� �ֻ��� ��Ʈ�� ���� 
	}

	return answer;
}

// ���� ���� ��ǥ ���� union
void makeUnion(int x, int y, vector<int>& root)
{
	if (x == y)
		return;

	x = find(x, root);
	y = find(y, root);

	if (x > y)
		root[x] = y;
	else
		root[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> root(n + 1);
	for (int i = 1; i <= n; i++)
		root[i] = i;

	int op, a, b;
	for (int i = 0;i < m;i++)
	{
		cin >> op >> a >> b;

		if (op == 0)
		{
			makeUnion(a, b, root);
		}
		else if (op == 1)
		{
			if (find(a, root) == find(b, root))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
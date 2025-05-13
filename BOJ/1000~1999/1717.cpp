#include <iostream>
#include <vector>
using namespace std;

// root 경로 압축
int find(int x, vector<int>& root)
{
	int answer = x;

	// 최상위 루트 검색
	while (answer != root[answer])
	{
		answer = root[answer];
	}

	// 압축
	while (x != answer)
	{
		int prev = x;
		x = root[x]; // x를 한 단계 상위로 (현재는 root의 압축 보장되어 있지 않음)
		root[prev] = answer; // 이전 x의 root를 위에서 검색한 최상위 루트로 압축 
	}

	return answer;
}

// 작은 수를 대표 수로 union
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
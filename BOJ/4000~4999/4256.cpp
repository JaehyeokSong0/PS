#include <iostream>
using namespace std;

#define MAXSIZE 1000+1
int preorder[MAXSIZE];
int inorder[MAXSIZE];

//현재의 루트 기준으로 inorder배열에서 왼쪽, 오른쪽 서브트리를 구분할 수 있다
void postorder(int root, int start, int end) //현재 서브트리의 root 및 배열에서의 인덱스 범위
{
	for (int i = start;i < end;i++)
	{
		if (inorder[i] == preorder[root]) //postorder: left -> right -> this 순서
		{
			postorder(root + 1, start, i); //왼쪽 서브트리, preorder에서 root+1은 왼쪽 서브트리의 루트노드
			postorder((root - start) + i + 1, i + 1, end); //오른쪽 서브트리, 현 위치 기준 i+1은 오른쪽 서브트리의 루트노드
			cout << preorder[root] << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; //테스트 케이스의 개수
	cin >> t;

	int n; //노드의 개수
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0;j < n;j++)
			cin >> preorder[j];
		for (int j = 0;j < n;j++)
			cin >> inorder[j];

		postorder(0, 0, n);

		cout << "\n";
	}

	return 0;
}
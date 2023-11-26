#include <iostream>
using namespace std;

#define MAXSIZE 1000+1
int preorder[MAXSIZE];
int inorder[MAXSIZE];

//������ ��Ʈ �������� inorder�迭���� ����, ������ ����Ʈ���� ������ �� �ִ�
void postorder(int root, int start, int end) //���� ����Ʈ���� root �� �迭������ �ε��� ����
{
	for (int i = start;i < end;i++)
	{
		if (inorder[i] == preorder[root]) //postorder: left -> right -> this ����
		{
			postorder(root + 1, start, i); //���� ����Ʈ��, preorder���� root+1�� ���� ����Ʈ���� ��Ʈ���
			postorder((root - start) + i + 1, i + 1, end); //������ ����Ʈ��, �� ��ġ ���� i+1�� ������ ����Ʈ���� ��Ʈ���
			cout << preorder[root] << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; //�׽�Ʈ ���̽��� ����
	cin >> t;

	int n; //����� ����
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
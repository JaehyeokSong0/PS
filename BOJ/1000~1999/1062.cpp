#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXALPHABET 26
bool alphabet[MAXALPHABET] = { false, }; //0~25�� a~z������ ���ĺ� ����
bool wordChar[MAXALPHABET] = { false, }; //word �Է¹����� ���� ���ĺ� ����
int wordCharCnt = 0; //wordChar�� ����� true�� ����
vector<string> word;
int n, k; //n:�ܾ��� ����, k:������ ����
int ret = 0; //�����	
int learned; //������� ��� ���ڼ�

void dfs(int x, int cnt)
{
	if (cnt == k) //k���� ���ڸ� ��� ��� ��� -> ��� ���ڵ�� �ܾ� ���� �� �ִ��� Ȯ��
	{
		int wordCnt = 0; //���� �� �ִ� �ܾ��� ��
		for (int i = 0; i < n; i++) //�� �ܾ�鿡 ����
		{
			bool canRead = true;
			for (int j = 0;j < word[i].length();j++) //���ڵ��� �ϳ��� �˻�
			{
				int ch = word[i][j] - 'a';
				if (!alphabet[ch]) //���� �� ���� �ܾ ���� ���
				{
					canRead = false;
					break;
				}
			}
			if (canRead)
				wordCnt++;
		}
		ret = max(ret, wordCnt);
	}
	else
	{
		for (int i = x; i < MAXALPHABET; i++) //�� ���ڵ鿡 ����
		{
			if (wordChar[i] && !alphabet[i]) //�����ϴ� �������� ���� ����� ���� ���ڶ��
			{
				alphabet[i] = true;
				dfs(i, cnt + 1);
				alphabet[i] = false; //dfs ���� �� �ٽ� false�� �ٲ�� ������ ���࿡ ���� X
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	alphabet['a' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;
	wordChar['a' - 'a'] = true;
	wordChar['n' - 'a'] = true;
	wordChar['t' - 'a'] = true;
	wordChar['i' - 'a'] = true;
	wordChar['c' - 'a'] = true;
	learned = 5;
	wordCharCnt = 5;

	if (k < 5) //a,n,t,i,c�� ��ο� ��̿� �⺻���� ���� �����̹Ƿ�
		cout << 0;
	else
	{
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			word.push_back(str.substr(4, str.length() - 8)); //���ξ�, ���̾� ������ �ܾ� push
			
			for (int j = 0;j < word[i].length();j++)
			{
				if (!wordChar[word[i][j] - 'a'])
				{
					wordChar[word[i][j] - 'a'] = true;
					wordCharCnt++;
				}
			}
				
		}
		if (wordCharCnt < k) //��� �� �ִ� ���ں��� �Էµ� ���ڰ� �� ������� ��� �ܾ ���� �� �����Ƿ�
			cout << n;
		else
		{
			dfs(0, learned);
			cout << ret;
		}
	}
	return 0;
}
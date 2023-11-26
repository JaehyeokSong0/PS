#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAXSIZE 1000+1
int lcs[MAXSIZE][MAXSIZE] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	str1 = "0" + str1;
	str2 = "0" + str2;
	int str1_len = str1.length();
	int str2_len = str2.length();

	for (int i = 1; i < str1_len; i++)
	{
		for (int j = 1; j < str2_len; j++)
		{
			if (str1[i] == str2[j]) //���� ���ڸ� ���ϴ� ���
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else //�ٸ� ���ڸ� ���� ��� �α� �� �� ū ���� ����
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	cout << lcs[str1_len - 1][str2_len - 1];

	return 0;
}
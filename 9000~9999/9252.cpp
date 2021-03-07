#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

#define MAXSIZE 1000+1
int lcs[MAXSIZE][MAXSIZE];

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

	//lcs 길이 구하기
	for (int i = 1; i < str1_len; i++)
	{
		for (int j = 1; j < str2_len; j++)
		{
			if (str1[i] == str2[j]) //같은 문자를 비교하는 경우
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else //다른 문자를 비교한 경우 인근 값 중 큰 숫자 대입
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	//lcs 길이 출력
	cout << lcs[str1_len - 1][str2_len - 1] << endl;

	//lcs 문자열 구하기
	stack<char> st;
	int i = str1_len - 1;
	int j = str2_len - 1;
	while (lcs[i][j] != 0)
	{
		int currLcs = lcs[i][j];
		if ((currLcs != lcs[i - 1][j]) && (currLcs != lcs[i][j - 1]))
		{
			st.push(str1[i]);
			i--;
			j--;
		}
		else
		{
			if (currLcs == lcs[i - 1][j])
				i--;
			else if (currLcs == lcs[i][j - 1])
				j--;
		}
	}
	//lcs 문자열 출력
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}

	return 0;
}
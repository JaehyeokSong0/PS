#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXALPHABET 26
bool alphabet[MAXALPHABET] = { false, }; //0~25에 a~z까지의 알파벳 저장
bool wordChar[MAXALPHABET] = { false, }; //word 입력받으며 나온 알파벳 저장
int wordCharCnt = 0; //wordChar에 저장된 true의 개수
vector<string> word;
int n, k; //n:단어의 개수, k:글자의 개수
int ret = 0; //결과값	
int learned; //현재까지 배운 글자수

void dfs(int x, int cnt)
{
	if (cnt == k) //k개의 글자를 모두 배운 경우 -> 배운 글자들로 단어 읽을 수 있는지 확인
	{
		int wordCnt = 0; //읽을 수 있는 단어의 수
		for (int i = 0; i < n; i++) //각 단어들에 대해
		{
			bool canRead = true;
			for (int j = 0;j < word[i].length();j++) //글자들을 하나씩 검사
			{
				int ch = word[i][j] - 'a';
				if (!alphabet[ch]) //읽을 수 없는 단어가 나온 경우
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
		for (int i = x; i < MAXALPHABET; i++) //각 글자들에 대해
		{
			if (wordChar[i] && !alphabet[i]) //등장하는 글자지만 아직 배우지 않은 글자라면
			{
				alphabet[i] = true;
				dfs(i, cnt + 1);
				alphabet[i] = false; //dfs 진입 후 다시 false로 바꿔야 이후의 시행에 영향 X
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

	if (k < 5) //a,n,t,i,c은 어두와 어미에 기본으로 들어가는 글자이므로
		cout << 0;
	else
	{
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			word.push_back(str.substr(4, str.length() - 8)); //접두어, 접미어 제거한 단어 push
			
			for (int j = 0;j < word[i].length();j++)
			{
				if (!wordChar[word[i][j] - 'a'])
				{
					wordChar[word[i][j] - 'a'] = true;
					wordCharCnt++;
				}
			}
				
		}
		if (wordCharCnt < k) //배울 수 있는 글자보다 입력된 글자가 더 적은경우 모든 단어를 읽을 수 있으므로
			cout << n;
		else
		{
			dfs(0, learned);
			cout << ret;
		}
	}
	return 0;
}
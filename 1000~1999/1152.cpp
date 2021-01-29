#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	string str;
	getline(cin, str);

	if (str.length() == 0) //빈 문자열일 경우
	{
		cout << 0;
		return 0;
	}

	int blankCnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			blankCnt++;
	}

	//문자열의 앞뒤에 공백이 있는 경우 (공백이 연속해서 나오지 않으므로 가장 처음과 끝만 검사)
	if (str[0] == ' ')
		blankCnt--;
	if (str[str.length() - 1] == ' ')
		blankCnt--;

	cout << blankCnt + 1;

	return 0;
}
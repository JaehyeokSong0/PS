#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	getline(cin, str);

	for (auto start = str.begin(); start < str.end(); start++)
	{
		if (*start == '<')
		{
			auto end = str.find('>', start - str.begin()) + str.begin();
			cout << str.substr(start - str.begin(), end - start + 1);
			start = end;
		}
		else if (*start == ' ')
		{
			cout << *start;
		}
		else
		{
			auto blankIt = str.find(' ', start - str.begin());
			auto tagIt = str.find('<', start - str.begin());

			auto blank = (blankIt != string::npos) ? blankIt + str.begin() : str.end();
			auto tag = (tagIt != string::npos) ? tagIt + str.begin() : str.end();

			if (blank == tag) // EOF
			{
				reverse(start, str.end());
				cout << str.substr(start - str.begin(), str.end() - start);
				break;
			}
			else if (blank > tag) // 공백 없음
			{
				reverse(start, tag);
				cout << str.substr(start - str.begin(), tag - start);
				start = tag - 1;
			}
			else // 공백 있음
			{
				reverse(start, blank);
				cout << str.substr(start - str.begin(), blank - start);
				start = blank - 1;
			}
		}
	}

	return 0;
}